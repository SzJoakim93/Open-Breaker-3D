#ifndef Application_H
#define Application_H

#include <cstdio>

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <gl/glu.h>

#include "Game.h"
#include "Menu.h"

class Application
{
    public:

        Application(char *frame_title, char * levelpath);
        ~Application();
        void eLoadProjectionMatrix(int width, int height, float near, float far);
        void handleSDL2Events(int & quit);
        void render();
    protected:
    private:
        Game * game;
        Menu * menu;
        int  width; // Az ablak szelessege pixelben.
        int  height; // Az ablak magassaga pixelben.
        int depth; // Szinmelyseg
        bool fullscreen; // Az ablak teljes kepernyos beallitasa.
        float _near; //a latotavolsag kezdete
        float _far; //latotavolsag
        SDL_Event event;
        Uint8 *keystates;
        int jatekresz; /*0: menu, 1: ingame, 2:game-over, 3: gyozObject, 4: vereseg
                         5: palyamenu, 6: beallitasok menu 7: felbontas
                         8: felbontas egyeni szelesseg 9: felbontas egyeni magassag*/

        Top * top;
        int index;
        char scorename[20];

        bool Sound;
        bool zene;
        int language;
        bool valtozas;
        bool top_valtozas;
        int setres;

        float ms[4];
        float md[4];
        float direction[4];
        float ld[4];
        float ls[4];
};

#endif // Application_H
