#ifndef Application_H
#define Application_H

#include <cstdio>

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Game.h"
#include "Menu.h"
#include "Appsettings.h"

class Application
{
    public:

        Application(char *frame_title, char * levelpath, ApplicationState * appState);
        ~Application();
        void eLoadProjectionMatrix(int width, int height, float near, float far);
        void handleSDL2Events();
        void render();
    protected:
    private:
        Game * game;
        Menu * menu;
        State * state;
        Appsettings appsettings;
        SDL_Event event;
        Uint8 *keystates;

        Top * top;
        int index;
        char scorename[20];
        bool top_valtozas;
        ApplicationState * appState;

        float ms[4];
        float md[4];
        float direction[4];
        float ld[4];
        float ls[4];

        friend void backToMenu(void* _application);
        friend void startGame(void* _params);
};

#endif // Application_H
