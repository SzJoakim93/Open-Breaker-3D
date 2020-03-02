#ifndef MENU_H
#define MENU_H

#include "Object.h"
#include "Game.h"
#include "Sound.h"

class Menu
{
    public:
        Menu(Top * top, int * s_width, int * s_height, bool * valtozas, int * language);
        ~Menu();
        void fel(int & jatekresz); //kurzor elmozditasa felfele
        void le(int & jatekresz); //kurzor elmozditasa lefele
        void balra(int & jatekresz); //kurzor elmozditasa balra
        void jobbra(int & jatekresz); //kurzor elmozditasa jobbra
        void rendering(int & jatekresz); //menu Objecteinek rendering(0)ese
        void rendering_res(int & jatekresz, int & setres); //menu Objecteinek rendering(0)ese
        int getcursor();
        void setmaxcursor(int becursor);
        void setcursor(int becursor);
        void setcursor();
        void sethangok(bool * behang, bool * bezene, bool * befullscreen);
        void enter(int & jatekresz, int & quit, Game & Game, int & width, int & height, int & setres);
        void mouse_event(const int & x, const int & y, int & jatekresz, Game & Game, int & quit, bool isClicked, Uint8 & isMouseMoving);
    protected:
    private:
        int cursor; //kurzor hanyadik menuponton van 0-tol kezdve
        int maxcursor; //maximum hany menupont van
        //Multi_Object * level_objects;
        int DB;
        bool * enableSound;
        bool * enableMusic;
        bool * fullscreen;
        int * language;
        int * s_width;
        int * s_height;
        bool * valtozas;
        char musicList[30][18];
        char levelList[30][18];
        int max_package;
        char on_title[4];
        char off_title[4];
        Object * level_objects[21];
        Object * score_titles[10];
        Object * player_titles[10];
        Object * sound_title;
        Object * music_title;
        Object * screen_title;
        Object ** screen_settings;
        Object * custom_title;
        Object * custom_res;
        Object * frame;
        Object ** obj_game_titles;
        Object * lang_title;
        Object * res_title;
        int selected;
        bool set_selected;
        char players[10][10];
        Sound sounds;
        Top * top;
};

#endif // MENU_H
