#ifndef STATE_H
#define STATE_H

#include <SDL/SDL.h>
#include "Appsettings.h"

class State
{
public:
    State(Appsettings * appsettings, SDL_Event * event, Uint8* keystates);
    virtual ~State();
    virtual void handleEvents() = 0;
    virtual void hanldeSDLEvents() = 0;
    virtual void rendering() = 0;
protected:
    SDL_Event * event;
    Uint8 * keystates;
    Appsettings * appsettings;
};

#endif //State_H