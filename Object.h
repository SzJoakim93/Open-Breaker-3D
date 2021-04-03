#ifndef OBJECT_H
#define OBJECT_H

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

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
        static void cameraTranslateZ(const float & x); //kamera mozgasa elore
        static void cameraTranslateX(const float & x); //kamera mozgasa oldalra
        static void cameraTranslateY(const float & x); //kamera mozgasa fel
        static void cameraRotateX(const int & x); //kamera mozgasa balra
        static void cameraRotateY(const int & x); //kamera mozgasa fel
        static int get_rCameraX();
        static int get_rCameraY();
        void translateZ(const float & x);
        void translateY(const float & y);
        void translateX(const float & z);
        void trans_gravity(const float & x);
        void rotateX(const int & x);
        void rotateY(const int & x);
        void rotateZ(const int & x);
        //setterek:
        void setTX(const float & x);
        void setTY(const float & y);
        void setTZ(const float & z);
        void setSX(const float & x);
        void setSY(const float & y);
        void setSZ(const float & z);
        void setRX(const int & bex);
        void setRY(const int & bey);
        void setRZ(const int & bez);
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
