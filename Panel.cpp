#include "Panel.h"

SDL_Event* Panel::event;
Uint8* Panel::keystates;
int Panel::width;
int Panel::height;

Panel::Panel(/* args */) :
    active(true), activeBtn(-1)
{
}

Panel::~Panel()
{
}

void Panel::addUI(UI* ui)
{
    elements.insert(ui);
}

void Panel::addUI_Button(UI_Button* button)
{
    buttons.insert(button);
}

void Panel::handleEvents()
{
    if (!active)
        return;

    for (int i = 0; i < buttons.size(); i++)
        buttons[i]->buttonEvents();

    if (keystates[SDLK_UP])
        switchFocus(-1);
    else if (keystates[SDLK_DOWN])
        switchFocus(1);
    else if (keystates[SDLK_RETURN] || keystates[SDLK_SPACE])
        buttons[activeBtn]->click();
}

void Panel::rendering()
{
    if (!active)
        return;

    for (int i = 0; i < elements.size(); i++)
        elements[i]->rendering();

    for (int i = 0; i < buttons.size(); i++)
        buttons[i]->rendering();
}

bool Panel::isActive()
{
    return active;
}

void Panel::switchFocus(const int x)
{
    if (activeBtn > -1)
        buttons[activeBtn]->setMark(false);
    
    if (activeBtn == -1)
        activeBtn = 0;
    else
    {
        activeBtn += x;
        if (activeBtn >= buttons.size())
            activeBtn = 0;
        else if (activeBtn < 0)
            activeBtn = buttons.size() - 1;
    }

    buttons[activeBtn]->setMark(true);
}

void Panel::initEvents(SDL_Event* _event, Uint8* _keystates, const int _width, const int _height)
{
    event = _event;
    keystates = _keystates;
    width = _width;
    height = _height;
}