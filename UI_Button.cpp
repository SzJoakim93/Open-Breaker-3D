#include "UI_Button.h"

SDL_Event * UI_Button::event;
const int * UI_Button::width;
const int * UI_Button::height;
vector<UI_Button*> UI_Button::buttonList;

UI_Button::UI_Button(float tx, float ty, float sx, float sy, char* texname, void (*callBack)(void*), void* object) :
    UI(tx, ty, sx, sy, texname, STRECH_TEXTURED)
{
    this->callBack = callBack;
    this->object = object;
    buttonList.insert(this);
}

UI_Button::~UI_Button()
{
    buttonList.remove(this);
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

bool UI_Button::click()
{
    return event->button.state == SDL_BUTTON_LEFT && mouseOver();
}

void UI_Button::initButtonEvents(SDL_Event * _event, const int * _width, const int * _height)
{
    event = _event;
    width = _width;
    height = _height;
}

void UI_Button::buttonEvents()
{
    for (int i = 0; i < buttonList.size(); i++)
        if (buttonList[i]->mouseOver())
        {
            if (buttonList[i]->texture->getCountOnObject() > 1 && buttonList[i]->getCurrentTexture() == 0)
                buttonList[i]->switchTexture(1);

            if (event->button.state == SDL_BUTTON_LEFT)
                buttonList[i]->callBack(buttonList[i]->object);
        }
        else if (buttonList[i]->getCurrentTexture() == 1)
            buttonList[i]->switchTexture(0);
}