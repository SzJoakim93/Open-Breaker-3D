#ifndef OBJECT_H
#define OBJECT_H

#include "GL/gl.h"
#include "SDL/SDL.h"
#include "gl/glu.h"

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <dirent.h>
#include <sys/stat.h>

#include "list.h"
#include "char_list.h"

#include "Texture.h"
#include "Model.h"

#define PI 3.141592
#define SPRITE 0x00000008

class Object
{
    public:
        Object();
        Object(float tx, float ty, float tz,
            int rx, int ry, int rz,
            float sx, float sy, float sz,
            Uint32 flags, char* texname, char* objname);
        ~Object();
        void rendering(const int & i);
        static void cVertical(const float & x); //kamera mozgasa elore
        static void cHorizontal(const float & x); //kamera mozgasa oldalra
        static void cLenghtical(const float & x); //kamera mozgasa fel
        void aelore(const float & x); //Object mozgasa elore
        void ahatra(const float & x); //Object mozgasa hatra
        static void cbalra(const int & x); //kamera mozgasa balra
        static void cjobbra(const int & x); //kamera mozgasa jobbra
        static void cfel(const int & x); //kamera mozgasa fel
        static void cle(const int & x); //kamera mozgasa le
        static int get_rCameraX();
        static int get_rCameraY();
        void trans_vertical(const float & x);
        void trans_lengthical(const float & y);
        void trans_horizontal(const float & z);
        void trans_gravity(const float & x);
        void rotateX(const int & x);
        void rotateY(const int & x);
        void rotateZ(const int & x);
        //setterek:
        void settx(const float & x);
        void setty(const float & y);
        void settz(const float & z);
        void setsx(const float & x);
        void setsy(const float & y);
        void setsz(const float & z);
        void setrx(const int & bex);
        void setry(const int & bey);
        void setrz(const int & bez);
        static void setcx(float bex);
        static void setcy(float bey);
        static void setcz(float bez);
        static void setrCameraX(int be);
        static void set_rCameraX(const float & x);
        static void set_rCameraY(const float & y);
        //getterek:
        float gettx();
        float getty();
        float gettz();
        static float getcx();
        static float getcy();
        static float getcz();
        float getsx();
        float getsy();
        float getsz();
        int getrx();
        int getry();
        int getrz();
        char* getObjname();
        bool operator ==(Object & other);
        bool isCollision();
        bool isActive();
        void setActive(const bool _active);
    protected:
    private:
        //Object koordinatai:
        eCoord3f transform;
        //kamera eltolas:
        static float cx;
        static float cy;
        static float cz;
         //Object elforgatasa:
        eCoord3i rotate;
         //kamera koruli forgatas
        static int rCameraX;
        static int rCameraY;
        //Object atmeretezese:
        eCoord3f scale;
        //blender file betoltese eseten az obj file elerese, rectangle eseten a "rectangle" szo
        char objname[32];

        bool active;
        bool isSprite;

        Model * model;
        Texture * texture;

        void eRenderMesh();
};

#endif // Object_H
