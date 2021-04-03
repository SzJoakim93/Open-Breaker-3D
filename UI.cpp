#include "UI.h"

UI::UI(float tx, float ty, float sx, float sy, char* texname, Uint32 flags)
{
    setCoords(tx, ty, sx, sy);
    setTexture(sx, sy, texname, flags);
    active = true;
    currentTexture = 0;
}

UI::UI(float tx, float ty, float sx, float sy)
{
    setCoords(tx, ty, sx, sy);
    active = true;
    currentTexture = 0;
}

void UI::setTexture(float sx, float sy, char* texname, Uint32 flags)
{
    char_list material_ids;
    texture = Texture::createTextures(texname);

    if (flags & STRECH_TEXTURED)
        model = new Model(1.0f, 1.0f);
    else if (flags & STRECH_TEXTURED_VERTICAL)
        model = new Model(1.0f, sy);
    else if (flags & STRECH_TEXTURED_HORIZONTAL)
        model = new Model(sx, 1.0f);
    /*else if (flags & PANEL)
        model = new Model(sx, 1.0f, "panel");*/
    else
        model = new Model(sx, sy);
}

void UI::setCoords(float tx, float ty, float sx, float sy)
{
    this->transform.x = transform_absolute.x = tx;
    this->transform.y = transform_absolute.y = ty;
    this->scale.x = sx;
    this->scale.y = sy;
}

UI::~UI()
{
    delete model;
    Texture::deleteTexture(texture);
}

void UI::setActive(const bool _active)
{
    active = _active;
}

void UI::rendering()
{
    if (active)
    {
        glPushMatrix();

        glTranslatef(transform_absolute.x, transform_absolute.y, -0.25f);
        glRotatef(-90, 1, 0, 0);
        glRotatef(90, 0, 1, 0);
        glScalef(scale.x, 1.0f, scale.y);

        glEnable(GL_TEXTURE_2D);

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        glBindTexture(GL_TEXTURE_2D, texture->getTexture(currentTexture));

        glVertexPointer(3, GL_FLOAT, sizeof(eCoord3f), &model->getMesh()[0].faces[0].a.x);
        glNormalPointer(GL_FLOAT, sizeof(eCoord3f), &model->getMesh()[0].normalcoords[0].a.x);
        glTexCoordPointer(2, GL_FLOAT, 0, &model->getMesh()[0].texcoords[0].a.x);

        glDrawArrays(GL_TRIANGLES, 0, model->getMesh()[0].faces.size() * 3);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);

        glDisable(GL_TEXTURE_2D);

        glPopMatrix();
    }

}

bool UI::isActive()
{
    return active;
}

void UI::switchTexture(const int x)
{
    currentTexture = x;
}

int UI::getCurrentTexture()
{
    return currentTexture;
}

float UI::getTX()
{
    return transform.x;
}

float UI::getTY()
{
    return transform.y;
}

int UI::GL_to_SDL_X(const float x)
{
    return (x+0.1f) * 2320 + 88;
}

int UI::GL_to_SDL_Y(const float x)
{
    return -1.0f*(x-0.1f) * 2320 + 8;
}

void UI::setTX(float x)
{
    this->transform.x = this->transform_absolute.x = x;
}

void UI::setTY(float y)
{
    this->transform.y = this->transform_absolute.y = y;
}

void UI::setSX(float x)
{
    this->scale.x = x;
}

void UI::setSY(float y)
{
    this->scale.y = y;
}