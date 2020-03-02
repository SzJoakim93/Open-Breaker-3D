#include "GL/gl.h"
#include "SDL/SDL.h"
#include "gl/glu.h"

#include "Application.h"
#include "Object.h"

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char *argv[])
{
    char levelpath[30] = {0};

    if (argc > 1 && !strcmp(argv[1], "-editor"))
        strcpy(levelpath, argv[2]);

    int quit;/* Az Application fo ciklusanak a futasat jelzi.
        Ha az erteke igazra allitodik, akkor az Application a
        kovetkezo iteracio elejen kilep.*/

    Application * application;
    srand(time(0));

begin_prog:

    application = new Application("Ball Breaker 3D v2.0beta2", levelpath); //kepernyo inicializalasa

    quit = 0; //kilepes feltetele

    while (!quit) //a fo ciklus kezdete
    {
        application->handleSDL2Events(quit); //az esemenyvezerlo megnyitasa (pl billentyuzetkezeles)
        application->render(); //kepernyo osszeallitasa
    }

    delete application;
    if (quit == 2)
    {
        SDL_Quit();
        goto begin_prog;
    }

    return 0;
}
