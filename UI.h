#ifndef UI_H
#define UI_H

#include "Coord.h"
#include "Texture.h"
#include "Model.h"

class UI
{
public:
    UI(float tx, float ty, float sx, float sy, char* texname, Uint32 flags);
    ~UI();
    void rendering();
    void setActive(const bool _active);
    bool isActive();
    void switchTexture(const int x);
    int getCurrentTexture();
    float getTX();
    float getTY();
    void setTX(float x);
    void setTY(float y);
    void setSX(float x);
    void setSY(float y);
protected:
    eCoord2f transform;
    eCoord2f transform_absolute;
    eCoord2f scale;
    Texture * texture;
    Model * model;
    bool active;
    int currentTexture;
    UI(float tx, float ty, float sx, float sy);
    void setCoords(float tx, float ty, float sx, float sy);
    void setTexture(float sx, float sy, char* texname, Uint32 flags);
    int GL_to_SDL_X(const float x);
    int GL_to_SDL_Y(const float x);

};

#endif // UI_H