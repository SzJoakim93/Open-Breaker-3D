
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

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

    ApplicationState appState; // Az Application fo ciklusanak a futasat jelzi.

    Application * application;
    srand(time(0));

begin_prog:

    application = new Application("Ball Breaker 3D v2.0beta2", levelpath, &appState); //kepernyo inicializalasa

    appState = RUN; //kilepes feltetele

    while (appState == RUN) //a fo ciklus kezdete
    {
        application->handleSDLEvents(); //az esemenyvezerlo megnyitasa (pl billentyuzetkezeles)
        application->render(); //kepernyo osszeallitasa
    }

    delete application;
    if (appState == RESTART)
        goto begin_prog;

    printf("Program has ended normally\n");
    SDL_Quit();

    return 0;
}
