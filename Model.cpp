#include "Model.h"

#include <fstream>
#include <string>
#include <iostream>
#include "helpers/sconvert.h"

list<Model*> Model::global_model;

Model::Model(char * objPath)
{
    char_list objnames;
    if (is_dir(objPath))
        load_files_from_dir(&objnames, objPath, ".OBJ", &animation_length);
    else
    {
        objnames.insert(objPath);
        animation_length=1;
    }

    //get mesh numbers in one object and material names
    meshCountOnObject = 0;
    std::ifstream file(*(objnames.begin()));

    while (file.good())
    {
        std::string str;

        file >> str;
        if (str == "o")
            meshCountOnObject++;
    }
    file.close();

    mesh = new eMesh[meshCountOnObject*animation_length];

    int j=0;
    for (char_list::Iterator i = objnames.begin(); i != objnames.end(); i++)
    {
        LoadMeshFromOBJ(*i, j);
        j+=meshCountOnObject;
    }

    for (int i=0; i<meshCountOnObject*animation_length; i++)
        eCalcMeshNormals(&mesh[i]);

    modelCount = 1;
    strcpy(objname, objPath);
}

Model::Model(float x, float y)
{
    mesh = new eMesh();
    modelCount = 1;
    meshCountOnObject = 1;
    animation_length = 1;

    mesh->faces.insert(
        Face(
            eCoord3f(-1.0, 0, -1.0),
            eCoord3f(1.0, 0, 1.0),
            eCoord3f(1.0, 0, -1.0)
        )
    );

    mesh->faces.insert(
        Face(
            eCoord3f(-1.0, 0, -1.0),
            eCoord3f(-1.0, 0, 1.0),
            eCoord3f(1.0, 0, 1.0)
        )
    );

    mesh->texcoords.insert(
        TexCoord(
            eCoord2f(0, 0),
            eCoord2f(y, x),
            eCoord2f(0, x)
        )
    );

    mesh->texcoords.insert(
        TexCoord(
            eCoord2f(0, 0),
            eCoord2f(y, 0),
            eCoord2f(y, x)
        )
    );

    mesh->normalcoords.insert(
        Face(
            eCoord3f(0.0, 1.0, 0.0),
            eCoord3f(0.0, 1.0, 0.0),
            eCoord3f(0.0, 1.0, 0.0)
        )
    );

    mesh->normalcoords.insert(
        Face(
            eCoord3f(0.0, 1.0, 0.0),
            eCoord3f(0.0, 1.0, 0.0),
            eCoord3f(0.0, 1.0, 0.0)
        )
    );

    eCalcMeshNormals(mesh);
    strcpy(objname, "rectangle");
}

Model::~Model()
{
    if (strcmp(objname, "rectangle") == 0)
        delete mesh;
    else
        delete [] mesh;
}

Model * Model::createModel(char * objname)
{
    //checking if obj has been already loaded
    for (list<Model*>::Iterator i=global_model.begin(); i!=global_model.end(); i++)
    {
        if (!strcmp(objname, (*i)->getModelName()))
        {
            //set iterator if obj already exist
            (*i)->modelCount++;
            return *i;

        }
    }

    //loading new obj if not exist
    Model * newModel = new Model(objname);
    global_model.insert(newModel);
    return newModel;

}

void Model::deleteModel(Model * model)
{
    model->modelCount--;
    if (model->modelCount == 0)
    {
        delete model;
        global_model.remove(model);
    }
}


const int & Model::getCountOnObject()
{
    return meshCountOnObject;
}

char * Model::getModelName()
{
    return objname;
}

eMesh* & Model::getMesh()
{
    return mesh;
}

void Model::LoadMeshFromOBJ(char *file, const int & begin)
{
    std::ifstream fd(file, std::ifstream::binary);
    if (!fd.is_open())
    {
        fprintf(stderr, "Error during loading obj file: %s\n", file);
        return;
    }

    int mesh_ptr=begin-1;

    vector<eCoord3f> vertexlist;

    int maxfacesNum=0;
    int current_maxfacesNum=0;

    while (fd.good())
    {
        std::string str;
        fd >> str;

        if (fd.eof())
        {
            break;
        }

        if (str == "o")
        {
            maxfacesNum = current_maxfacesNum + 1;
            mesh_ptr++;

            vertexlist.clear();
        }
        else if (str == "f")
        {
            int a, b, c;

            fd >> a >> b >> c;
            if (a > current_maxfacesNum)
                current_maxfacesNum = a;
            if (b > current_maxfacesNum)
                current_maxfacesNum = b;
            if (c > current_maxfacesNum)
                current_maxfacesNum = c;

            if (fd.eof())
            {
                break;
            }

            a-=maxfacesNum;
            b-=maxfacesNum;
            c-=maxfacesNum;

            Face face;
            TexCoord texcoords;
            Face normalcoords;

            face.a = vertexlist[a];
            face.b = vertexlist[b];
            face.c = vertexlist[c];
            texcoords.a.x = 1.0f;
            texcoords.a.y = 0.0f;
            texcoords.b.x = 1.0f;
            texcoords.b.y = 1.0f;
            texcoords.c.x = 0.0f;
            texcoords.c.y = 1.0f;

            mesh[mesh_ptr].faces.insert(face);
            mesh[mesh_ptr].texcoords.insert(texcoords);

            b = c;

            while (fd.good())
            {
                std::string str;
                fd >> str;
                if (fd.eof())
                {
                    break;
                }

                if (str == "f" || str == "o")
                {
                    int offset = -str.length();
                    fd.seekg(offset, fd.cur);
                    break;
                }
                else
                {
                    c = std::stoi(str);

                    c-=maxfacesNum;

                    face.a = vertexlist[a];
                    face.b = vertexlist[b];
                    face.c = vertexlist[c];
                    texcoords.a.x = 1.0f;
                    texcoords.a.y = 0.0f;
                    texcoords.b.x = 1.0f;
                    texcoords.b.y = 1.0f;
                    texcoords.c.x = 0.0f;
                    texcoords.c.y = 1.0f;

                    mesh[mesh_ptr].faces.insert(face);
                    mesh[mesh_ptr].texcoords.insert(texcoords);
                    b = c;
                }
            }
        }
        else if (str == "v")
        {
            eCoord3f v;
            fd >> v.x >> v.y >> v.z;

            if (fd.eof())
            {
                break;
            }

            vertexlist.insert(v);
        }
    }

    fd.close();

}

void Model::eCalcMeshNormals(eMesh *m)
{
    int i;
    for (i = 0; i <m->faces.size(); ++i)
    {
        Face *f = &m->faces[i];

        eCoord3f *a = (eCoord3f*)&f->a;
        eCoord3f *b = (eCoord3f*)&f->b;
        eCoord3f *c = (eCoord3f*)&f->c;

        eCoord3f v1;
        v1.x = b->x - a->x;
        v1.y = b->y - a->y;
        v1.z = b->z - a->z;

        eCoord3f v2;
        v2.x = c->x - a->x;
        v2.y = c->y - a->y;
        v2.z = c->z - a->z;

        eCoord3f r = eCrossProduct(v1, v2);
        Face newNormalCoord;
        newNormalCoord.a = r;
        newNormalCoord.b = r;
        newNormalCoord.c = r;
        m->normalcoords.insert(newNormalCoord);
    }
}

eCoord3f Model::eCrossProduct(const eCoord3f & a, const eCoord3f & b)
{
    eCoord3f r;

    r.x = a.y * b.z - a.z * b.y;
    r.y = a.z * b.x - a.x * b.z;
    r.z = a.x * b.y - a.y * b.x;

    return r;
}
