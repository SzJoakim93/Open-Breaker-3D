#include "State.h"

State::State( Appsettings * appsettings, SDL_Event * event, Uint8* keystates) :
    appsettings(appsettings), event(event), keystates(keystates)
{
}

State::~State()
{
}
