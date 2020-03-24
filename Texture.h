#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <gl/glu.h>

#include "FileManager.h"

#define STRECH_TEXTURED 0x00000001
#define STRECH_TEXTURED_VERTICAL 0x00000002
#define STRECH_TEXTURED_HORIZONTAL 0x00000004

class Texture
{
private:
    char texname[64];
    GLuint* texture;
    int texCountOnObjects;
    int texCount;
    void loadBMPTexture(char *filename, GLuint & textureid);
    char createTextureFromSDLSurface(SDL_Surface *surf, GLuint & textureid);    
    static list<Texture*> global_texture;
public:
    Texture(char * texturePath);
    ~Texture();
    void increaseCount();
    void decreaseCount();
    const int & getCount();
    const int & getCountOnObject();
    char * getTexName();
    const GLuint & getTexture(const int & x);

    static Texture * createTextures(char * texture);
    static void deleteTexture(Texture * texture);
};

#endif //Texture_H