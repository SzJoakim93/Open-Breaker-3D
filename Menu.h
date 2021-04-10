#ifndef MENU_H
#define MENU_H

#include "UI_Label.h"
#include "UI_Button.h"
#include "Panel.h"
#include "Game.h"
#include "Sound.h"

struct StartGameParams
{
    void* application;
    int level;
} typedef StartGameParams;

class Menu : public State
{
    public:
        Menu(Appsettings * appsettings, SDL_Event * event, Uint8* keystates, Top * top,
            void (*startGame)(void*),void* application);
        virtual ~Menu();
        virtual void handleEvents();
        virtual void hanldeSDLEvents();
        virtual void rendering();
    protected:
    private:
        int cursor; //kurzor hanyadik menuponton van 0-tol kezdve
        int maxcursor; //maximum hany menupont van
        //Multi_UI * level_UIs;
        ApplicationState * appState;
        StartGameParams * startGameParams;
        int DB;

        char musicList[30][18];
        char levelList[30][18];
        int max_package;
        char on_title[4];
        char off_title[4];
        Panel mainPanel;
        Panel levelPanel;
        Panel settingsPanel;
        Panel aboutPanel;
        Panel scorePanel;
        Panel helpPanel;
        UI_Button * mainButtons[7];
        UI * title;
        UI * panels[4];
        UI_Label * score_titles[10];
        UI_Label * player_titles[10];
        UI * sound_title;
        UI * music_title;
        UI ** screen_settings;
        UI * custom_title;
        UI * custom_res;
        UI * frame;
        UI_Button ** levelTitles;
        UI * lang_title;
        UI * res_title;
        int selected;
        bool set_selected;
        char players[10][10];
        Sound sounds;
        Top * top;
        void hideAll();

        friend void showLevels(void* _menu);
        friend void showMain(void* _menu);
        friend void showSettings(void* _menu);
        friend void showScores(void* _menu);
        friend void showHelp(void* _menu);
        friend void showAbout(void* _menu);
        friend void doQuit(void* _menu);
};

#endif // MENU_H
