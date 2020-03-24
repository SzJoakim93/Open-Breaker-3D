#include "Application.h"

Application::Application(char *frame_title, char * levelpath)
{
    jatekresz = 0;

    //ctor
    scorename[0] = 0;
    top = new Top[10];
    this->depth = 32;
    this->_near=0.2;
    this->_far=30.0;
    this->valtozas=false;
    this->top_valtozas=false;
    this->setres=0;
    keystates = SDL_GetKeyState(NULL);
    SDL_Init(SDL_INIT_EVERYTHING);
    /*freopen( "CON", "w", stdout );
    freopen( "CON", "w", stderr );
    fprintf(stdout, "Initialize OPEN-GL system...");*/

    FILE * file = fopen("settings.ini", "r");

    int temp;
    fscanf(file, "screen_width=%d\n", &width);
    fscanf(file, "screen_height=%d\n", &height);
    fscanf(file, "fullscreen=%d\n", &temp);
    fullscreen=temp;
	fscanf(file, "sound=%d\n", &temp);
	Sound= temp;
	fscanf(file, "music=%d\n", &temp);
	zene= temp;
	fscanf(file, "language=%d\n", &language);

	fclose(file);

    //a kepernyo beallitasa
	if (fullscreen)
	{
		SDL_SetVideoMode(width, height, depth,
						 SDL_OPENGL | SDL_FULLSCREEN);
	}
	else
	{
		SDL_SetVideoMode(width, height, depth,
						 SDL_OPENGL);
	}

	SDL_WM_SetCaption(frame_title, 0);

    menu = new Menu(top, &width, &height, &valtozas, &language);
    menu->sethangok(&Sound, &zene, &fullscreen);
    game = new Game(levelpath, top, scorename,  &width, &height, &language);
    game->sethangok(&Sound, &zene);

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

	file = fopen("top.txt", "r");
    for (int i=0; i<10; i++)
    {
        fscanf(file, "%s", top[i].name);
        fscanf(file, "%d", &(top[i].score));
    }

    fclose(file);
	//glClearColor(1.0, 1.0, 1.0, 0.0);

	eLoadProjectionMatrix(width, height, _near, _far);
    glEnable(GL_NORMALIZE);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_LIGHT0);
    glEnableClientState(GL_NORMAL_ARRAY);
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
    if (valtozas)
    {
        FILE * file = fopen("settings.ini", "w");
        fprintf(file, "screen_width=%d\n", width);
        fprintf(file, "screen_height=%d\n", height);
        fprintf(file, "fullscreen=%d\n", fullscreen);
        fprintf(file, "sound=%d\n", Sound);
        fprintf(file, "music=%d\n", zene);
        fprintf(file, "language=%d\n", language);

        fclose(file);
    }

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
    gluPerspective(45, (float) width / (float) height, _near, _far);
}

void Application::handleSDL2Events(int & quit)
{
    while (SDL_PollEvent(&event))
    {
        if (keystates[SDLK_ESCAPE])
        {
            if (jatekresz == 0)
                quit = true;
            if (jatekresz > 0)
            {
                if (jatekresz == 1)
                {
                    game->reset();
                }

                jatekresz = 0;

                menu->setmaxcursor(6);
                //menu->setcursor(0);
            }
        }

        if (jatekresz == 1 && event.type == SDL_KEYDOWN)
        {

            if (event.key.keysym.sym == SDLK_LEFT)
                game->leftKeyDown();

            if (event.key.keysym.sym == SDLK_RIGHT)
                game->rightKeyDown();

            if (event.key.keysym.sym == SDLK_SPACE)
                game->launch();

            if ((game->getLife() == 0 || game->getCompleted()) && top[9].score < game->getScore())
            {
                static int ci=0;
                if (keystates[SDLK_BACKSPACE] || keystates[SDLK_DELETE]) {
                    ci--;
                    scorename[ci] = 0;
                }
                if (keystates[SDLK_q]) {
                    scorename[ci] = 'q';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_w]) {
                    scorename[ci] = 'w';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_e]) {
                    scorename[ci] = 'e';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_r]) {
                    scorename[ci] = 'r';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_t]) {
                    scorename[ci] = 't';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_z]) {
                    scorename[ci] = 'z';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_u]) {
                    scorename[ci] = 'u';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_i]) {
                    scorename[ci] = 'i';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_o]) {
                    scorename[ci] = 'o';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_p]) {
                    scorename[ci] = 'p';
                    scorename[ci+1] = 0;
                    ci++;
                }

                if (keystates[SDLK_a]) {
                    scorename[ci] = 'a';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_s]) {
                    scorename[ci] = 's';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_d]) {
                    scorename[ci] = 'd';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_f]) {
                    scorename[ci] = 'f';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_g]) {
                    scorename[ci] = 'g';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_h]) {
                    scorename[ci] = 'h';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_j]) {
                    scorename[ci] = 'j';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_k]) {
                    scorename[ci] = 'k';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_l]) {
                    scorename[ci] = 'l';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_y]) {
                    scorename[ci] = 'y';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_x]) {
                    scorename[ci] = 'x';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_c]) {
                    scorename[ci] = 'c';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_v]) {
                    scorename[ci] = 'v';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_b]) {
                    scorename[ci] = 'b';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_n]) {
                    scorename[ci] = 'n';
                    scorename[ci+1] = 0;
                    ci++;
                }
                if (keystates[SDLK_m]) {
                    scorename[ci] = 'm';
                    scorename[ci+1] = 0;
                    ci++;
                }
            }
        }

        if (event.type == SDL_KEYUP)
        {
            if (event.key.keysym.sym == SDLK_LEFT)
                game->leftKeyUp();

            if (event.key.keysym.sym == SDLK_RIGHT)
                game->rightKeyUp();
        }


        if (jatekresz == 1)
        {
            /*if (event.button.type == SDL_MOUSEBUTTONUP)
            {
                if (event.button.x > 470 && event.button.x < 530 && event.button.y > 310 && event.button.y < 340)
                {
                    Game->mouse_ok(true, jatekresz);
                    if (top[9].score < Game->getScore())
                    {
                        index=0;
                        while (top[index].score >= Game->getScore())
                            index++;

                        for (int i=9; i>index; i--)
                            top[i] = top[i-1];

                        top[index].score = Game->getScore();
                        strcpy(top[index].name, scorename);

                        top_valtozas = true;
                    }
                }
            }
            else
            {
                if (event.button.x > 470 && event.button.x < 530 && event.button.y > 310 && event.button.y < 340)
                    Game->mouse_ok(false, jatekresz);
            }*/
            if (keystates[SDLK_RETURN])
            {
                //Game->enter(jatekresz);
                jatekresz = 0;
                if (top[9].score < game->getScore())
                {
                    index=0;
                    while (top[index].score >= game->getScore())
                        index++;

                    for (int i=9; i>index; i--)
                        top[i] = top[i-1];

                    top[index].score = game->getScore();
                    strcpy(top[index].name, scorename);

                    top_valtozas = true;
                }
            }

        }
        if (jatekresz == 0 || jatekresz > 1)
        {
            if (event.button.state == SDL_BUTTON_LEFT)
                menu->mouse_event(event.button.x, event.button.y, jatekresz, *game, quit, true, event.type);
            else
                menu->mouse_event(event.button.x, event.button.y, jatekresz, *game, quit, false, event.type);

            if (keystates[SDLK_UP])
                menu->fel(jatekresz);
            if (keystates[SDLK_DOWN])
                menu->le(jatekresz);
            if (keystates[SDLK_LEFT])
                menu->balra(jatekresz);
            if (keystates[SDLK_RIGHT])
                menu->jobbra(jatekresz);

            if (keystates[SDLK_RETURN])
                menu->enter(jatekresz, quit, *game, width, height, setres);

        }

        if (jatekresz == 7 || jatekresz == 8)
        {
            if (keystates[SDLK_0] || keystates[SDLK_KP0])
                setres=setres*10;
            if (keystates[SDLK_1] || keystates[SDLK_KP1])
                setres=setres*10+1;
            if (keystates[SDLK_2] || keystates[SDLK_KP2])
                setres=setres*10+2;
            if (keystates[SDLK_3] || keystates[SDLK_KP3])
                setres=setres*10+3;
            if (keystates[SDLK_4] || keystates[SDLK_KP4])
                setres=setres*10+4;
            if (keystates[SDLK_5] || keystates[SDLK_KP5])
                setres=setres*10+5;
            if (keystates[SDLK_6] || keystates[SDLK_KP6])
                setres=setres*10+6;
            if (keystates[SDLK_7] || keystates[SDLK_KP7])
                setres=setres*10+7;
            if (keystates[SDLK_8] || keystates[SDLK_KP8])
                setres=setres*10+8;
            if (keystates[SDLK_9] || keystates[SDLK_KP9])
                setres=setres*10+9;

            if (keystates[SDLK_BACKSPACE] || keystates[SDLK_DELETE])
                setres=setres/10;
        }
    }

    if (jatekresz == 1)
        game->esemenyek(jatekresz);
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

    if (jatekresz == 0 || jatekresz > 1 && (jatekresz < 8 || jatekresz == 9))
        menu->rendering(jatekresz);
    if (jatekresz == 1)
        game->rendering(jatekresz);

    if (jatekresz == 7 || jatekresz == 8)
        menu->rendering_res(jatekresz, setres);


    SDL_GL_SwapBuffers();
    SDL_Delay(30);
}
