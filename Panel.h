#ifndef PANEL_H
#define PANEL_H

#include <SDL/SDL.h>

#include "UI_Label.h"
#include "UI_Button.h"
#include "vector.h"

class Panel
{
public:
    Panel(/* args */);
    ~Panel();
    void addUI(UI* ui);
    void addUI_Button(UI_Button* button);
    void handleEvents();
    void handleKeyEvents();
    void rendering();
    bool isActive();
    void setActive(const bool x);
    static void initEvents(SDL_Event* _event, Uint8* _keystates, const int _width, const int _height);
private:
    static SDL_Event * event;
    static Uint8* keystates;
    static int width;
    static int height;
    vector<UI*> elements;
    vector<UI_Button*> buttons;
    int activeBtn;
    UI* frame;
    bool active;
    void switchFocus(const int x);
};

#endif //Panel_H