#ifndef MESH_H
#define MESH_H

#include <cstdio>

#include "FileManager.h"
#include "Coord.h"


typedef struct Face
{
    eCoord3f a, b, c;
    Face() {}
    Face(eCoord3f _a, eCoord3f _b, eCoord3f _c)
        : a(_a), b(_b), c(_c) {}
};

typedef struct TexCoord
{
    eCoord2f a, b, c;
    TexCoord() {}
    TexCoord(eCoord2f _a, eCoord2f _b, eCoord2f _c)
        : a(_a), b(_b), c(_c) {}
};

typedef struct eMesh
{
    vector<Face> faces;
    vector<TexCoord> texcoords;
    vector<Face> normalcoords;
};

class Model
{
public:
    Model(char * objPath);
    Model(float x, float y);
    ~Model();
    eMesh* & getMesh();
    const int & getCountOnObject();
    char * getModelName();
    static Model * createModel(char * objname);
    static void deleteModel(Model * model);
private:
    char objname[64];
    eMesh * mesh;
    int meshCountOnObject;
    int modelCount;
    int animation_length;
    void LoadMeshFromOBJ(char *file, const int & begin);
    void eCalcMeshNormals(eMesh *m);
    eCoord3f eCrossProduct(const eCoord3f & a, const eCoord3f & b);
    static list<Model*> global_model;
};

#endif //Mesh_H