#ifndef UI_BUTTON_H
#define UI_BUTTON_H

#include "UI.h"

class UI_Button : public UI
{
public:
    UI_Button(float tx, float ty, float sx, float sy, char* texname, void (*callBack)(void*), void* object);
    ~UI_Button();
    static void initButtonEvents(SDL_Event * _event, const int * _width, const int * _height);
    static void buttonEvents();
private:
    void (*callBack)(void*);
    void* object;
    bool mouseOver();
    bool click();
    static SDL_Event * event;
    static const int * width;
    static const int * height;
    static vector<UI_Button*> buttonList;
};

#endif //UI_Button_H