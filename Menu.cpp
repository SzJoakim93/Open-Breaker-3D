#include "Menu.h"

void showMain(void * _menu)
{
    Menu * menu = (Menu*)_menu;
    menu->hideAll();
    menu->title->setActive(true);
    menu->activePanel = &menu->mainPanel;
}

void showLevels(void* _menu)
{
    Menu* menu = (Menu*)_menu;
    menu->hideAll();
    menu->levelPanel.setActive(true);
    menu->activePanel = &menu->levelPanel;
}

void showSettings(void * _menu)
{
    Menu* menu = (Menu*)_menu;
    menu->hideAll();
    menu->settingsPanel.setActive(true);
    menu->activePanel = &menu->settingsPanel;
}

void showScores(void * _menu)
{
    Menu* menu = (Menu*)_menu;
    menu->hideAll();
    menu->scorePanel.setActive(true);
    menu->activePanel = &menu->scorePanel;
}

void showHelp(void * _menu)
{
    Menu* menu = (Menu*)_menu;
    menu->hideAll();
    menu->helpPanel.setActive(true);
    menu->activePanel = &menu->helpPanel;
}

void showAbout(void * _menu)
{
    Menu* menu = (Menu*)_menu;
    menu->hideAll();
    menu->aboutPanel.setActive(true);
    menu->activePanel = &menu->aboutPanel;
}

void doQuit(void * _menu)
{
    Menu* menu = (Menu*)_menu;
    menu->appState = QUIT;
}

Menu::Menu(Appsettings * appsettings, SDL_Event * event, Uint8* keystates, Top * top,
    ApplicationState& appState, void (*startGame)(void*), void* application) :
    appState(appState), sounds(appsettings), State(appsettings, event, keystates)
{
    cursor = 0;
    maxcursor = 6;

    char lang_path[32];
    if (appsettings->getLanguage() == HUN)
    {
        strcpy(lang_path, "Fonts/hungarian");
        /*strcpy(on_title, "be");
        strcpy(off_title, "ki");*/
    }
    else
    {
        strcpy(lang_path, "Fonts/english");
        /*strcpy(on_title, "on");
        strcpy(off_title, "off");*/
    }

    mainPanel.addUI_Button(new UI_Button(-0.03, -0.098, //koordinatak
                             0.007, 0.014, //atmeretezes
                             "Fonts/english/start.bmp;Fonts/english/start_c.bmp", &showLevels, this));

    char temp[32];
    sprintf(temp, "%s/settings.bmp;%s/settings_c.bmp", lang_path, lang_path);
    mainPanel.addUI_Button(new UI_Button(0.0, -0.098, //koordinatak
                             0.007, 0.014, //atmeretezes
                             temp, &showSettings, this));

    sprintf(temp, "%s/scores.bmp;%s/scores_c.bmp", lang_path, lang_path);
    mainPanel.addUI_Button(new UI_Button(0.03, -0.098, //koordinatak
                             0.007, 0.014, //atmeretezes
                             temp, &showScores, this));

    sprintf(temp, "%s/help.bmp;%s/help_c.bmp", lang_path, lang_path);
    mainPanel.addUI_Button(new UI_Button(0.06, -0.098, //koordinatak
                             0.007, 0.014, //atmeretezes
                             temp, &showHelp, this));

    sprintf(temp, "%s/about.bmp;%s/about_c.bmp", lang_path, lang_path);
    mainPanel.addUI_Button(new UI_Button(0.09, -0.098, //koordinatak
                             0.007, 0.014, //atmeretezes
                             temp, &showAbout, this));

    sprintf(temp, "%s/quit.bmp;%s/quit_c.bmp", lang_path, lang_path);
    mainPanel.addUI_Button(new UI_Button(0.12, -0.098, //koordinatak
                             0.007, 0.014, //atmeretezes
                             temp, &doQuit, this));

    
    title = new UI(0.0, 0.0, //koordinatak
                             0.0675, 0.09, //atmeretezes
                             "Textures/title.bmp", STRECH_TEXTURED);
    mainPanel.addUI(title);


    strcpy(temp, lang_path);
    strcat(temp, "/Help_w.bmp");
    helpPanel.addUI(new UI(0.0, 0.0, //koordinatak
                             0.11, 0.11, //atmeretezes
                             temp, STRECH_TEXTURED));
    helpPanel.addUI_Button(new UI_Button(0.0, -0.08, 0.007, 0.014, 
        "Fonts/english/ok.bmp;Fonts/english/ok_c.bmp", &showMain, this));

    strcpy(temp, lang_path);
    strcat(temp, "/About_w.bmp");
    aboutPanel.addUI(new UI(0.0, 0.0, //koordinatak
                             0.055, 0.11, //atmeretezes
                             temp, STRECH_TEXTURED));
    aboutPanel.addUI_Button(new UI_Button(0.0, -0.04, 0.007, 0.014, 
        "Fonts/english/ok.bmp;Fonts/english/ok_c.bmp", &showMain, this));

    scorePanel.addUI(new UI(0.0, 0.0, //koordinatak
                             0.0775, 0.11, //atmeretezes
                             "Fonts/english/scores_w.bmp", STRECH_TEXTURED));
    scorePanel.addUI_Button(new UI_Button(0.0, -0.065, 0.007, 0.014, 
        "Fonts/english/ok.bmp;Fonts/english/ok_c.bmp", &showMain, this));

    settingsPanel.addUI(new UI(0.0, 0.0, //koordinatak
                             0.11, 0.11, //atmeretezes
                             "Fonts/english/settings_w.bmp", STRECH_TEXTURED));
    settingsPanel.addUI_Button(new UI_Button(0.0, -0.055, 0.007, 0.014, 
        "Fonts/english/ok.bmp;Fonts/english/ok_c.bmp", &showMain, this));

    /*for (int i=0; i<16; i++)
        screen_settings[i] = new UI(-0.06+0.1*(i/9), 0.06-0.01*(i%9), //koordinatak
                                0.0025, 0.0012, //atmeretezes
                                "Fonts/letters", STRECH_TEXTURED);*/

    activePanel = &mainPanel;

    FILE * packages = fopen("Levels/Packages.txt", "r");
    fscanf(packages, "%d\n", &max_package);
    startGameParams = new StartGameParams [max_package];
    char char_game_titles[32];

    for (int j=0; j<max_package; j++)
    {
        startGameParams[j].application = application;
        startGameParams[j].level = (j*10)+1;
        fscanf(packages, "%s\n", char_game_titles);
        levelPanel.addUI_Button(new UI_Button(-0.06+0.06*j, 0.06, //koordinatak
                                0.025, 0.025, //atmeretezes
                                char_game_titles, startGame, &startGameParams[j]));
    }

    fclose(packages);

    levelPanel.addFrame(new UI(-0.06, 0.06, //koordinatak
                             0.03, 0.03, //atmeretezes
                             "Fonts/frame.bmp", STRECH_TEXTURED));

    this->top = top;

    for (int i=0; i<10; i++)
    {
        sprintf(temp, "%d", top[i].score);
        scorePanel.addUI_Label(new UI_Label(0.02, 0.053-0.0105*i, //koordinatak
                             0.002, 0.002, //atmeretezes
                             "Fonts/letters", temp));
        scorePanel.addUI_Label(new UI_Label(-0.05, 0.053-0.0105*i, //koordinatak
                             0.002, 0.002, //atmeretezes
                             "Fonts/letters", top[i].name));

    }

    sounds.play_music("Music/s.wav");

    hideAll();
    showMain(this);
}

Menu::~Menu()
{
    delete [] startGameParams;
}

void Menu::handleEvents()
{

}

void Menu::hanldeSDLEvents()
{
    mainPanel.handleEvents();
    levelPanel.handleEvents();
    settingsPanel.handleEvents();
    scorePanel.handleEvents();
    helpPanel.handleEvents();
    aboutPanel.handleEvents();
    activePanel->handleKeyEvents();
}

void Menu::rendering()
{
    mainPanel.rendering();
    levelPanel.rendering();
    scorePanel.rendering();
    helpPanel.rendering();
    aboutPanel.rendering();
    settingsPanel.rendering();
}

void Menu::hideAll()
{
    title->setActive(false);
    settingsPanel.setActive(false);
    helpPanel.setActive(false);
    aboutPanel.setActive(false);
    scorePanel.setActive(false);
    levelPanel.setActive(false);
}
