#include "Panel.h"

SDL_Event* Panel::event;
Uint8* Panel::keystates;
int Panel::width;
int Panel::height;

Panel::Panel(/* args */) :
    active(true), activeBtn(0), frame(NULL)
{
}

Panel::~Panel()
{
    for (int i = 0; i < elements.size(); i++)
        delete elements[i];
    for (int i = 0; i < labels.size(); i++)
        delete labels[i];
    for (int i = 0; i < buttons.size(); i++)
        delete buttons[i];                
}

void Panel::addUI(UI* ui)
{
    elements.insert(ui);
}

void Panel::addUI_Label(UI_Label* label)
{
    labels.insert(label);
}

void Panel::addUI_Button(UI_Button* button)
{
    button->setFrame(frame);
    buttons.insert(button);
}

void Panel::addFrame(UI* frame)
{
    this->frame = frame;
    for (int i = 0; i < buttons.size(); i++)
        buttons[i]->setFrame(frame);
}

void Panel::handleEvents()
{
    if (!active)
        return;

    for (int i = 0; i < buttons.size(); i++)
        buttons[i]->buttonEvents();
}

void Panel::handleKeyEvents()
{
    if (!active)
        return;

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

    for (int i = 0; i < buttons.size(); i++)
        buttons[i]->rendering();

    for (int i = 0; i < labels.size(); i++)
        labels[i]->rendering();

    for (int i = 0; i < elements.size(); i++)
        elements[i]->rendering();

    if (frame)
        frame->rendering();
}

bool Panel::isActive()
{
    return active;
}

void Panel::setActive(const bool x)
{
    active = x;
}

void Panel::switchFocus(const int x)
{
    buttons[activeBtn]->setMark(false);

    activeBtn += x;
    if (activeBtn >= buttons.size())
        activeBtn = 0;
    else if (activeBtn < 0)
        activeBtn = buttons.size() - 1;

    buttons[activeBtn]->setMark(true);
    
    if (frame)
    {
        frame->setTX(buttons[activeBtn]->getTX());
        frame->setTY(buttons[activeBtn]->getTY());
    }
}

void Panel::initEvents(SDL_Event* _event, Uint8* _keystates, const int _width, const int _height)
{
    event = _event;
    keystates = _keystates;
    width = _width;
    height = _height;
}