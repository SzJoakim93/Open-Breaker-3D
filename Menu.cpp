#include "Menu.h"

void showMain(void * _menu)
{
    Menu * menu = (Menu*)_menu;
    menu->hideAll();
    menu->title->setActive(true);
}

void showLevels(void* _menu)
{
    Menu* menu = (Menu*)_menu;
    menu->hideAll();
    menu->frame->setActive(true);
    for (int i=0; i<menu->max_package; i++)
        menu->levelTitles[i]->setActive(true);
}

void showSettings(void * _menu)
{
    Menu* menu = (Menu*)_menu;
    menu->hideAll();
    menu->panels[3]->setActive(true);
    menu->mainButtons[6]->setActive(true);
}

void showScores(void * _menu)
{
    Menu* menu = (Menu*)_menu;
    menu->hideAll();
    for (int i = 0; i < 10; i++)
    {
        menu->score_titles[i]->setActive(true);
        menu->player_titles[i]->setActive(true);
    }

    menu->panels[2]->setActive(true);
    menu->mainButtons[6]->setActive(true);
}

void showHelp(void * _menu)
{
    Menu* menu = (Menu*)_menu;
    menu->hideAll();
    menu->panels[0]->setActive(true);
    menu->mainButtons[6]->setActive(true);
}

void showAbout(void * _menu)
{
    Menu* menu = (Menu*)_menu;
    menu->hideAll();
    menu->panels[1]->setActive(true);
    menu->mainButtons[6]->setActive(true);
}

void doQuit(void * _menu)
{
    Menu* menu = (Menu*)_menu;
    *(menu->appState) = QUIT;
}

Menu::Menu(Appsettings * appsettings, SDL_Event * event, Uint8* keystates, Top * top, ApplicationState * appState,
    void (*startGame)(void*), void* application) :
    appState(appState), sounds(appsettings), State(appsettings, event, keystates)
{
    cursor = 0;
    maxcursor = 6;

    /**A menu UIei:**/
    char lang_path[32];
    if (appsettings->getLanguage() == HUN)
    {
        strcpy(lang_path, "Fonts/hungarian");
        strcpy(on_title, "be");
        strcpy(off_title, "ki");
    }
    else
    {
        strcpy(lang_path, "Fonts/english");
        strcpy(on_title, "on");
        strcpy(off_title, "off");
    }

    title = new UI(0.0, 0.0, //koordinatak
                             0.0675, 0.09, //atmeretezes
                             "Textures/title.bmp", STRECH_TEXTURED);


    mainButtons[0] = new UI_Button(-0.03, -0.098, //koordinatak
                             0.007, 0.014, //atmeretezes
                             "Fonts/english/start.bmp;Fonts/english/start_c.bmp", &showLevels, this);
    char temp[32];
    sprintf(temp, "%s/settings.bmp;%s/settings_c.bmp", lang_path, lang_path);
    mainButtons[1] = new UI_Button(0.0, -0.098, //koordinatak
                             0.007, 0.014, //atmeretezes
                             temp, &showSettings, this);

    sprintf(temp, "%s/scores.bmp;%s/scores_c.bmp", lang_path, lang_path);
    mainButtons[2] = new UI_Button(0.03, -0.098, //koordinatak
                             0.007, 0.014, //atmeretezes
                             temp, &showScores, this);

    sprintf(temp, "%s/help.bmp;%s/help_c.bmp", lang_path, lang_path);
    mainButtons[3] = new UI_Button(0.06, -0.098, //koordinatak
                             0.007, 0.014, //atmeretezes
                             temp, &showHelp, this);

    sprintf(temp, "%s/about.bmp;%s/about_c.bmp", lang_path, lang_path);
    mainButtons[4] = new UI_Button(0.09, -0.098, //koordinatak
                             0.007, 0.014, //atmeretezes
                             temp, &showAbout, this);

    sprintf(temp, "%s/quit.bmp;%s/quit_c.bmp", lang_path, lang_path);
    mainButtons[5] = new UI_Button(0.12, -0.098, //koordinatak
                             0.007, 0.014, //atmeretezes
                             temp, &doQuit, this);

    mainButtons[6] = new UI_Button(0.0, -0.08, //koordinatak
                             0.007, 0.014, //atmeretezes
                             "Fonts/english/ok.bmp;Fonts/english/ok_c.bmp",
                             &showMain, this);

    strcpy(temp, lang_path);
    strcat(temp, "/Help_w.bmp");
    panels[0] = new UI(0.0, 0.0, //koordinatak
                             0.11, 0.11, //atmeretezes
                             temp, STRECH_TEXTURED);

    strcpy(temp, lang_path);
    strcat(temp, "/About_w.bmp");
    printf("%s\n", temp);
    panels[1] = new UI(0.0, 0.0, //koordinatak
                             0.055, 0.11, //atmeretezes
                             temp, STRECH_TEXTURED);

    panels[2] = new UI(0.0, 0.0, //koordinatak
                             0.0775, 0.11, //atmeretezes
                             "Fonts/english/scores_w.bmp", STRECH_TEXTURED);

    panels[3] = new UI(0.0, 0.0, //koordinatak
                             0.11, 0.11, //atmeretezes
                             "Fonts/english/settings_w.bmp", STRECH_TEXTURED);

    frame = new UI(-0.06, 0.06, //koordinatak
                             0.03, 0.03, //atmeretezes
                             "Fonts/frame.bmp", STRECH_TEXTURED);

    screen_settings = new UI* [16];

    for (int i=0; i<16; i++)
        screen_settings[i] = new UI(-0.06+0.1*(i/9), 0.06-0.01*(i%9), //koordinatak
                                0.0025, 0.0012, //atmeretezes
                                "Fonts/letters", STRECH_TEXTURED);

    FILE * packages = fopen("Levels/Packages.txt", "r");
    fscanf(packages, "%d\n", &max_package);
    levelTitles = new UI_Button* [max_package];
    startGameParams = new StartGameParams [max_package];
    char char_game_titles[32];

    for (int j=0; j<max_package; j++)
    {
        startGameParams[j].application = application;
        startGameParams[j].level = (j*10)+1;
        fscanf(packages, "%s\n", char_game_titles);
        levelTitles[j] = new UI_Button(-0.06+0.06*j, 0.06, //koordinatak
                                0.025, 0.025, //atmeretezes
                                char_game_titles, startGame, &startGameParams[j]);
    }

    fclose(packages);

    this->top = top;

    for (int i=0; i<10; i++)
    {
        sprintf(temp, "%d", top[i].score);
        score_titles[i] = new UI_Label(0.02, 0.053-0.0105*i, //koordinatak
                             0.0025, 0.0012, //atmeretezes
                             "Fonts/letters", temp);

        player_titles[i] = new UI_Label(-0.05, 0.053-0.0105*i, //koordinatak
                             0.0025, 0.0012, //atmeretezes
                             "Fonts/letters", top[i].name);
    }

    sounds.play_music("Music/s.wav");

    hideAll();
    showMain(this);
}

Menu::~Menu()
{
    for (int i=0; i<7; i++)
        delete mainButtons[i];
    for (int i=0; i<4; i++)
        delete panels[i];
    delete title;
    delete frame;

    for (int i=0; i<10; i++)
        delete score_titles[i];

    for (int i=0; i<10; i++)
        delete player_titles[i];

    /*delete sound_title;
    delete music_title;
    delete screen_title;*/

    /*delete lang_title;
    delete res_title;*/



    for (int i=0; i<16; i++)
        delete screen_settings[i];
    delete [] screen_settings;

    for (int j=0; j<max_package; j++)
        delete levelTitles[j];
    delete [] levelTitles;
    delete [] startGameParams;
}

void Menu::handleEvents()
{

}

void Menu::rendering()
{
    for (int i=0; i<10; i++)
    {
        score_titles[i]->rendering();
        player_titles[i]->rendering();
    }
    for (int i = 0; i < 7; i++)
        mainButtons[i]->rendering();
    for (int i = 0; i < 4; i++)
        panels[i]->rendering();
    title->rendering();
    for (int i = 0; i < max_package; i++)
        levelTitles[i]->rendering();
    frame->rendering();
}

void Menu::hideAll()
{
    for (int i=0; i<4; i++)
        panels[i]->setActive(false);
    for (int i=0; i<max_package; i++)        
        levelTitles[i]->setActive(false);
    frame->setActive(false);
    title->setActive(false);
    mainButtons[6]->setActive(false);

    for (int i = 0; i < 10; i++)
    {
        score_titles[i]->setActive(false);
        player_titles[i]->setActive(false);
    }
}
