#ifndef UI_BUTTON_H
#define UI_BUTTON_H

#include "UI.h"

class UI_Button : public UI
{
public:
    UI_Button(float tx, float ty, float sx, float sy, char* texname, void (*callBack)(void*), void* object);
    ~UI_Button();
    void buttonEvents();
    void click();
    void setMark(const bool x);
    void setFrame(UI* frame);
    static void initButtonEvents(SDL_Event * _event, const int * _width, const int * _height);
private:
    void (*callBack)(void*);
    void* object;
    UI* frame;
    bool mouseOver();
    static SDL_Event * event;
    static const int * width;
    static const int * height;
};

#endif //UI_Button_H