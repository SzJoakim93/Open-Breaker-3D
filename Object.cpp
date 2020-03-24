#include "Object.h"

float Object::cx = 0.0;
float Object::cy = 0.0;
float Object::cz = 0.0;
int Object::rCameraX = 25;
int Object::rCameraY = 50;

Object::Object(float tx, float ty, float tz, int rx, int ry, int rz, float sx, float sy, float sz, Uint32 flags, char* texname, char* objname)
{
    //ctor
    this->transform.x = tx;
    this->transform.y = ty;
    this->transform.z = tz;
    this->rotate.x = rx;
    this->rotate.y = ry;
    this->rotate.z = rz;
    this->scale.x = sx;
    this->scale.y = sy;
    this->scale.z = sz;
    this->active = true;
    strcpy(this->objname, objname);

    texture = Texture::createTextures(texname);

    if (!strcmp(objname, "rectangle"))
    {
        if (flags & STRECH_TEXTURED)
            model = new Model(1.0f, 1.0f);
        else if (flags & STRECH_TEXTURED_VERTICAL)
            model = new Model(1.0f, sz);
        else if (flags & STRECH_TEXTURED_HORIZONTAL)
            model = new Model(sx, 1.0f);
        else
            model = new Model(sx, sz);
    }
    else
        model = Model::createModel(objname);

    isSprite = flags & SPRITE;
}

Object::~Object()
{
    if (!strncmp(objname, "rectangle", 7))
        delete model;
    else
        Model::deleteModel(model);

    if (strcmp(texture->getTexName(), "NULL"))
        Texture::deleteTexture(texture);
}

void Object::eRenderMesh()
{
    for (int i=0; i<model->getCountOnObject() && i<texture->getCountOnObject(); i++)
    {
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_LIGHTING);
        glEnable(GL_NORMALIZE);

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        /*glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
        glMaterialfv(GL_FRONT, GL_AMBIENT, texture->getMaterial(i)->ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, texture->getMaterial(i)->diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, texture->getMaterial(i)->specular);*/

        glBindTexture(GL_TEXTURE_2D, texture->getTexture(i));


        glVertexPointer(3, GL_FLOAT, sizeof(eCoord3f), &model->getMesh()[i].faces[0].a.x);
        glNormalPointer(GL_FLOAT, sizeof(eCoord3f), &model->getMesh()[i].normalcoords[0].a.x);
        glTexCoordPointer(2, GL_FLOAT, 0, &model->getMesh()[i].texcoords[0].a.x);

        glDrawArrays(GL_TRIANGLES, 0, model->getMesh()[i].faces.size() * 3);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);

        glDisable(GL_TEXTURE_2D);
        glDisable(GL_LIGHTING);
        glDisable(GL_NORMALIZE);
    }
}

void Object::rendering(const int & i)
{
    if (active)
    {
        glPushMatrix();

        //az Object elforgatasa a kamerahoz kepest
        glRotatef(rCameraY, 1, 0, 0);
        glRotatef(rCameraX, 0, 1, 0);

        glTranslatef(cx, cy, cz);
        glTranslatef(transform.x, transform.y, transform.z); //eltolas az abszolut helyre

        if (isSprite)
            glRotatef(-rCameraX, 0, 1, 0);

        //az Object elforgatasa az abszolut helyzetetehez kepest
        glRotatef(rotate.x, 1, 0, 0);
        glRotatef(rotate.z, 0, 0, 1);
        glRotatef(rotate.y, 0, 1, 0);

        glScalef(scale.x, scale.y, scale.z); //nagyitas/kicsinyites

        eRenderMesh();

        glPopMatrix();
    }
}

void Object::settx(const float & x)
{
    this->transform.x = x;
}

void Object::setty(const float & y)
{

    this->transform.y = y;
}

void Object::settz(const float & z)
{

    this->transform.z = z;
}

void Object::setsx(const float & x)
{
    this->scale.x = x;

}

void Object::setsy(const float & y)
{
    this->scale.y = y;

}

void Object::setsz(const float & z)
{
    this->scale.z = z;

}

void Object::setcx(float bex)
{
    cx = bex;
}

void Object::setcy(float bey)
{
    cy = bey;
}

void Object::setcz(float bez)
{
    cz = bez;
}

void Object::setrCameraX(int be)
{
    rCameraX = be;
}

void Object::setrx(const int & x)
{
    this->rotate.x = x;
}

void Object::setry(const int & y)
{
    this->rotate.y = y;
}

void Object::setrz(const int & z)
{
    this->rotate.z = z;
}

float Object::gettx()
{
    return transform.x;
}

float Object::getty()
{
    return transform.y;
}

float Object::gettz()
{
    return transform.z;
}

float Object::getcx()
{
    return cx;
}

float Object::getcy()
{
    return cy;
}

float Object::getcz()
{
    return cz;
}

float Object::getsx()
{
    return scale.x;
}

float Object::getsy()
{
    return scale.y;
}

float Object::getsz()
{
    return scale.z;
}

int Object::getrx()
{
    return rotate.x;
}

int Object::getry()
{
    return rotate.y;
}

int Object::getrz()
{
    return rotate.z;
}

int Object::get_rCameraX()
{
    return rCameraX;
}

int Object::get_rCameraY()
{
    return rCameraY;
}

void Object::rotateX(const int & x)
{
    rotate.x+=x;
    if (rotate.x > 359)
        rotate.x = 0;
}

void Object::rotateY(const int & x)
{
    rotate.y+=x;
    if (rotate.y > 359)
        rotate.y = 0;
}

void Object::rotateZ(const int & x)
{
    rotate.z+=x;
    if (rotate.z > 359)
        rotate.z = 0;
}

void Object::cVertical(const float & x)
{
    cz+=x;
}

void Object::cHorizontal(const float & x)
{
    cx+=x;
}

void Object::cLenghtical(const float & x)
{
    cy+=x;
}

void Object::cbalra(const int & x)
{
    rCameraX-=x;
    if (rCameraX < 0)
        rCameraX = 358;
}

void Object::cjobbra(const int & x)
{
    rCameraX+=x;
    if (rCameraX > 358)
        rCameraX = 0;

}

void Object::cfel(const int & x)
{
    if (x < 35 && (rCameraY > 290 || rCameraY < 70+(x<<1)))
        rCameraY-=x;
    if (rCameraY < 0)
        rCameraY = 358;
}

void Object::cle(const int & x)
{
    if (x < 35 && (rCameraY > 290-(x<<1) || rCameraY < 70))
        rCameraY+=x;
    if (rCameraY > 358)
        rCameraY = 0;

}

void Object::trans_horizontal(const float & x)
{
    transform.x+=x;
}
void Object::trans_lengthical(const float & y)
{
    transform.y+=y;
}

void Object::trans_vertical(const float & z)
{
    transform.z+=z;
}

void Object::set_rCameraX(const float & x)
{
    rCameraX = x;
}

void Object::set_rCameraY(const float & y)
{
    rCameraY = y;
}

char* Object::getObjname()
{
    return objname;
}

bool Object::operator ==(Object & other)
{
    if (active && other.active)
    {
        if (other.getry() == 0 || other.getry() == 180)
        {
            if (this->gettx() + this->getsx()  > other.gettx() - (other.getsx()/* *(space/100.0)*/)  &&
            this->gettx() - this->getsx()  < other.gettx() + (other.getsx()/* *(space/100.0)*/)  &&
            this->gettz() + this->getsz()  > other.gettz() - (other.getsz()/* *(space/100.0)*/)  &&
            this->gettz() - this->getsz()  < other.gettz() + (other.getsz()/* *(space/100.0)*/) )
                return true;
            else
                return false;
        }
        else
        {
            if (this->gettx() + this->getsx()  > other.gettx() - (other.getsz()/* *(space/100.0)*/)  &&
            this->gettx() - this->getsx()  < other.gettx() + (other.getsz()/* *(space/100.0)*/)  &&
            this->gettz() + this->getsz()  > other.gettz() - (other.getsx()/* *(space/100.0)*/)  &&
            this->gettz() - this->getsz()  < other.gettz() + (other.getsx()/* *(space/100.0)*/) )
                return true;
            else
                return false;
        }
    }

}

bool Object::isActive()
{
    return active;
}

void Object::setActive(const bool _active)
{
    active = _active;
}
