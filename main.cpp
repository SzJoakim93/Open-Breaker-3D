#include "GL/gl.h"
#include "SDL/SDL.h"
#include "gl/glu.h"

#include "Alkalmazas.h"
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

    int quit;/* Az alkalmazas fo ciklusanak a futasat jelzi.
        Ha az erteke igazra allitodik, akkor az alkalmazas a
        kovetkezo iteracio elejen kilep.*/

    Alkalmazas * alkalmazas;
    srand(time(0));

begin_prog:

    alkalmazas = new Alkalmazas("Ball Breaker 3D v2.0beta2", levelpath); //kepernyo inicializalasa

    quit = 0; //kilepes feltetele

    while (!quit) //a fo ciklus kezdete
    {
        alkalmazas->handleSDL2Events(quit); //az esemenyvezerlo megnyitasa (pl billentyuzetkezeles)
        alkalmazas->render(); //kepernyo osszeallitasa
    }

    delete alkalmazas;
    if (quit == 2)
    {
        SDL_Quit();
        goto begin_prog;
    }

    return 0;
}
