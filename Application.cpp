#include "Application.h"

void backToMenu(void* _application)
{
    Application * application = (Application*)(_application);
    application->game->stop();
    application->state = application->menu;
}

void startGame(void* _params)
{
    StartGameParams * params = (StartGameParams*)_params;
    Application * application = (Application*)(params->application);
    application->game->start(params->level);
    application->state = application->game;
}

Application::Application(char *frame_title, char * levelpath, ApplicationState * appState)
{
    //ctor
    top = new Top[10];
    this->appState = appState;
    this->top_valtozas=false;
    keystates = SDL_GetKeyState(NULL);
    SDL_Init(SDL_INIT_EVERYTHING);
    /*freopen( "CON", "w", stdout );
    freopen( "CON", "w", stderr );*/
    fprintf(stdout, "Initialize OPEN-GL system...\n");

    //a kepernyo beallitasa
    SDL_SetVideoMode(appsettings.getWidth(), appsettings.getHeight(),
                        appsettings.getDepth(),
                        appsettings.isFullscreen() ? (SDL_OPENGL | SDL_FULLSCREEN) : (SDL_OPENGL));

	SDL_WM_SetCaption(frame_title, 0);

    fprintf(stdout, "OPEN-GL system initialized.\n");

    FILE * file = fopen("top.txt", "r");
    for (int i=0; i<10; i++)
    {
        fscanf(file, "%s", top[i].name);
        fscanf(file, "%d", &(top[i].score));
    }

    fclose(file);

    fprintf(stdout, "Top list loaded.\n");

    menu = new Menu(&appsettings, &event, keystates, top, &startGame, this);
    fprintf(stdout, "Menu loaded.\n");
    game = new Game(&appsettings, &event, keystates, levelpath, top, &backToMenu, this);
    fprintf(stdout, "Game initialized.\n");
    state = menu;

    direction[0] = -0.1;
    direction[1] = 0.1;
    direction[2] = 0.5;
    direction[3] = 0.0;

	for (int i=0; i<4; i++)
	{
	    ms[i] = 1;
	    md[i] = 1;

	   /* if (i<3)
            direction[i] = -0.01;
        else
            direction[i] = 0.0;*/
        ld[i] = 1;
        ls[i] = 1;
	}

	//glClearColor(1.0, 1.0, 1.0, 0.0);

	eLoadProjectionMatrix(appsettings.getWidth(), appsettings.getHeight(), appsettings.getNear(), appsettings.getFar());
    glEnable(GL_NORMALIZE);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_LIGHT0);
    glEnableClientState(GL_NORMAL_ARRAY);

    Panel::initEvents(&event, keystates, appsettings.getWidth(), appsettings.getHeight());
    UI_Button::initButtonEvents(&event, &appsettings.getWidth(), &appsettings.getHeight());

    fprintf(stdout, "Framework initialized\n");
}

Application::~Application()
{
    if (top_valtozas)
    {
        FILE * file = fopen("top.txt", "w");
        for (int i=0; i<10; i++)
        {
            fprintf(file, "%s\n", top[i].name);
            fprintf(file, "%d\n", top[i].score);
        }
    }

    delete [] top;

    glDisable(GL_BLEND);
    glDisable(GL_LIGHTING);
    glDisable(GL_NORMALIZE);
    glDisableClientState(GL_NORMAL_ARRAY);

    delete game;
    delete menu;
}

//a lataotavolsag megadasa
void Application::eLoadProjectionMatrix(int width, int height, float near, float far)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float) width / (float) height, near, far);
}

void Application::handleSDLEvents()
{
    while (SDL_PollEvent(&event))
    {
        if (keystates[SDLK_ESCAPE])
        {
            if (state == menu)
                *appState = QUIT;
            else if (state == game)
            {
                game->stop();
                state = menu;
            }
        }

        state->hanldeSDLEvents();
    }

    state->handleEvents();
}

void Application::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 8);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ms);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, md);
    glLightfv(GL_LIGHT0, GL_POSITION, direction);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, ld);
    glLightfv(GL_LIGHT0, GL_SPECULAR, ls);

    state->rendering();

    SDL_GL_SwapBuffers();
    SDL_Delay(30);
}
