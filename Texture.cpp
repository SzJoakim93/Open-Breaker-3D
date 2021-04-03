#include "Texture.h"

list<Texture*> Texture::global_texture;

Texture::Texture(char * texturePath)
{
    char_list texturelist;
    int i;
    int sum;
    i = strlen(texturePath);
    if (texturePath[i-4] == '.' &&  texturePath[i-3] == 't' && texturePath[i-2] == 'x' && texturePath[i-1] == 't')
        load_files_from_txt(&texturelist, texturePath, &sum);
    else if (texturePath[i-4] == '.' && (texturePath[i-3] == 'b' && texturePath[i-2] == 'm' && texturePath[i-1] == 'p' || texturePath[i-3] == 'B' && texturePath[i-2] == 'M' && texturePath[i-1] == 'P'))
        str_split_list(&texturelist, texturePath, ';', &sum);
    else //if textures stored in a folder
        load_files_from_dir(&texturelist, texturePath, ".BMP", &sum);

    texture = new GLuint[sum];
    glGenTextures(sum, texture);
    texCountOnObjects = sum;

    char_list::Iterator it = texturelist.begin();
    i=0;
    for (; it != texturelist.end(); ++it, i++)
        loadBMPTexture(*it, texture[i]);

    texCount = 1;
    strcpy(texname, texturePath);
}

Texture::~Texture()
{
    glDeleteTextures(texCountOnObjects, texture);
    
    if (texCountOnObjects > 1)
        delete [] texture;
    else
        delete texture;
}

Texture * Texture::createTextures(char * texture)
{
    /**loading texture(s)**/
    //checking, that this texture has been already loaded

    for (list<Texture*>::Iterator i = global_texture.begin(); i != global_texture.end(); i++)
    {
        if (!strcmp(texture, ((*i)->getTexName())))
        {
            (*i)->increaseCount();
            return *i;
        }
    }

    //if texture not be loaded, it will be loaded
    Texture * new_textureid = new Texture(texture);
    global_texture.insert(new_textureid);
    return new_textureid;
}

void Texture::deleteTexture(Texture * texture)
{
    texture->texCount--;
    if (texture->texCount == 0)
    {
        delete texture;
        Texture::global_texture.remove(texture);
    }
}

void Texture::increaseCount()
{
    texCount++;
}

void Texture::decreaseCount()
{
    texCount--;
}

const int & Texture::getCount()
{
    return texCount;
}

const int & Texture::getCountOnObject()
{
    return texCountOnObjects;
}

char * Texture::getTexName()
{
    return texname;
}

const GLuint & Texture::getTexture(const int & x)
{
    return texture[x];
}

char Texture::createTextureFromSDLSurface(SDL_Surface *surf, GLuint & textureid)
{
    glGetError();

    glBindTexture(GL_TEXTURE_2D, textureid);

    int pixels = surf->w * surf->h * 4;
    unsigned char *surfacedata = (unsigned char*) surf->pixels;
    unsigned char *data = (unsigned char*) malloc(sizeof(unsigned char) * pixels);
    int i;

    for (i = 0; i < pixels; i += 4)
    {
        data[i + 0] = surfacedata[i + 2];
        data[i + 1] = surfacedata[i + 1];
        data[i + 2] = surfacedata[i + 0];
        data[i + 3] = surfacedata[i + 3];
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    if (pixels > 16)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // ezt a ket sort rakd vissza kommentbe es probald ki, hogy mit csinal
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }

    free(data);

    return 0;
}


void Texture::loadBMPTexture(char *filename, GLuint & textureid)
{
    char error = 1;

    if (textureid)
    {
        SDL_Surface *image = SDL_LoadBMP(filename);
        if (!image)
        {
            fprintf(stderr, "Error during loading texture: %s\n", filename);
            image = SDL_LoadBMP("error.bmp");
        }
        SDL_Surface *optimized = NULL;
        if (image)
        {
            optimized = SDL_DisplayFormat(image);

            SDL_FreeSurface(image);

            if (optimized)
            {
                if (!createTextureFromSDLSurface(optimized, textureid))
                {
                    error = 0;
                }
                SDL_FreeSurface(optimized);
            }
        }
    }

    if (error)
    {
        fprintf(stderr, "Error during loading texture: %s\n", filename);
    }
}
