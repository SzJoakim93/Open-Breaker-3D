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
        ApplicationState& appState, void (*startGame)(void*),void* application);
        virtual ~Menu();
        virtual void handleEvents();
        virtual void hanldeSDLEvents();
        virtual void rendering();
    protected:
    private:
        int cursor; //kurzor hanyadik menuponton van 0-tol kezdve
        int maxcursor; //maximum hany menupont van
        ApplicationState& appState;
        StartGameParams * startGameParams;
        int DB;

        char musicList[30][18];
        char levelList[30][18];
        int max_package;
        Panel mainPanel;
        Panel levelPanel;
        Panel settingsPanel;
        Panel aboutPanel;
        Panel scorePanel;
        Panel helpPanel;
        Panel * activePanel;
        UI * title;
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
