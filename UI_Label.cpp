#include "UI_Label.h"
#include "FileManager.h"

UI_Label::UI_Label(float tx, float ty, float sx, float sy, char* texname, char* _title)
    : UI(tx, ty, sx, sy, texname, STRECH_TEXTURED)
{
    strcpy(title, _title);
}

UI_Label::~UI_Label()
{
}

void UI_Label::rendering()
{
    if (active)
    {
        int i=0;
        int j=0;

        while (title[i] != 0)
        {
            if (title[i] != ' ' && title[i] != '_')
            {
                glPushMatrix();

                glTranslatef(transform_absolute.x+(i-j)*scale.y*2.1f, transform_absolute.y, -0.24999f);
                glRotatef(-90, 1, 0, 0);
                glRotatef(90, 0, 1, 0);
                glScalef(scale.x, 1.0f, scale.y);

                glEnable(GL_TEXTURE_2D);

                glEnableClientState(GL_VERTEX_ARRAY);
                glEnableClientState(GL_TEXTURE_COORD_ARRAY);

                glVertexPointer(3, GL_FLOAT, sizeof(eCoord3f), &model->getMesh()[0].faces[0].a.x);
                glTexCoordPointer(2, GL_FLOAT, 0, &model->getMesh()[0].texcoords[0].a.x);

                if (title[i] >= 'a' && title[i] <= 'z')
                    glBindTexture(GL_TEXTURE_2D, texture->getTexture(10+title[i]-'a'));
                else if (title[i] >= '0' && title[i] <= '9')
                    glBindTexture(GL_TEXTURE_2D, texture->getTexture(title[i]-'0'));
                else if (title[i] == '/') //manage hungarian letters
                {
                    i++;
                    j++;
                    glBindTexture(GL_TEXTURE_2D, texture->getTexture(36+title[i]-'0'));
                }
                else if (title[i] == '.')
                    glBindTexture(GL_TEXTURE_2D, texture->getTexture(46));
                

                glDrawArrays(GL_TRIANGLES, 0, model->getMesh()[0].faces.size() * 3);

                glDisableClientState(GL_VERTEX_ARRAY);
                glDisableClientState(GL_TEXTURE_COORD_ARRAY);

                glDisable(GL_TEXTURE_2D);

                glPopMatrix();
            }
            i++;
        }
    }

}

void UI_Label::setGlobalScale()
{
    
}

void UI_Label::setText(const char * _text)
{
    strcpy(title, _text);
}

const char * UI_Label::getText()
{
    return title;
}

bool UI_Label::clicked(const int mouse_x, const int mouse_y, const int width, const int height)
{

    /*
    X:
    -0.1f -> 88
    0.0f -> 320
    0.1f -> 552
    
    Y:
    -0.1f -> 472
    0.0f -> 240
    0.1f -> 8
    */

    float screen_scaler = height / 480.0;
    int offset = (width-640.0*screen_scaler)/2.0;

    return active &&
        mouse_x > GL_to_SDL_X(transform_absolute.x - scale.x)*screen_scaler+offset &&
        mouse_x < GL_to_SDL_X(transform_absolute.x + scale.x*strlen(title))*screen_scaler+offset &&
        mouse_y < GL_to_SDL_Y(transform_absolute.y - scale.y)*screen_scaler &&
        mouse_y > GL_to_SDL_Y(transform_absolute.y + scale.y)*screen_scaler;
}