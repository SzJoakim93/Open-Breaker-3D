#include "UI_Button.h"

SDL_Event * UI_Button::event;
const int * UI_Button::width;
const int * UI_Button::height;

UI_Button::UI_Button(float tx, float ty, float sx, float sy, char* texname, void (*callBack)(void*), void* object) :
    UI(tx, ty, sx, sy, texname, STRECH_TEXTURED)
{
    this->callBack = callBack;
    this->object = object;
}

UI_Button::~UI_Button()
{

}

bool UI_Button::mouseOver()
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

    float screen_scaler = *height / 480.0;
    int offset = (*width-640.0*screen_scaler)/2.0;

    return active &&
        event->button.x > GL_to_SDL_X(transform_absolute.x - scale.y)*screen_scaler+offset &&
        event->button.x < GL_to_SDL_X(transform_absolute.x + scale.y)*screen_scaler+offset &&
        event->button.y < GL_to_SDL_Y(transform_absolute.y - scale.x)*screen_scaler &&
        event->button.y > GL_to_SDL_Y(transform_absolute.y + scale.x)*screen_scaler;
}

void UI_Button::click()
{
    callBack(object);
}

void UI_Button::setMark(const bool x)
{
    if (texture->getCountOnObject() > 1)
        switchTexture(x ? 1 : 0);
}

void UI_Button::initButtonEvents(SDL_Event * _event, const int * _width, const int * _height)
{
    event = _event;
    width = _width;
    height = _height;
}

void UI_Button::buttonEvents()
{
    if (mouseOver())
    {
        if (texture->getCountOnObject() > 1 && getCurrentTexture() == 0)
            switchTexture(1);

        if (event->button.state == SDL_BUTTON_LEFT)
            callBack(object);
    }
    else if (getCurrentTexture() == 1 && event->type == SDL_MOUSEMOTION)
        switchTexture(0);
}