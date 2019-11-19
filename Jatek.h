#ifndef JATEK_H
#define JATEK_H

#include "Object.h"
#include "Hang.h"
#include <dirent.h>
//#include <windows.h>

#include <cstring>
#include <cstdio>

#define MAX_LEVEL 20

typedef struct Top
{
    int score;
    char name[20];
} Top;

class Jatek
{
    public:
        Jatek(char * level_path, Top * top, char * scorename, int * width, int * height, int * language);
        ~Jatek();
        void load(char * path);
        void esemenyek(int & jatekresz);
        void balgomb();
        void jobbgomb();
        void balgomb_fel();
        void jobbgomb_fel();
        void enter(int & jatekresz);
        void rendering(int & jatekresz);
        void zene(char * eleres);
        void zene_stop();
        void reset();
        void sethangok(bool * behang, bool * bezene);
        void start(const int & level);
        void launch();
        int getLife();
        int getScore();
        bool getCompleted();
    protected:
    private:
        void print(int x, Object & Object);
        Object * stars[3];
        Object * aljzat;
        Object * fal1;
        Object * fal2;
        Object * fal3;
        Object * fal4;
        Object * padle;
        Object ** titles;
        Object ** ball;
        Object ** Objectek;
        Object ** bonuses;
        Object * life_title;
        Object * ammo_title;
        Object * score_title;
        Object * level_title;
        Object * block_title;
        Object * best_title;
        Object * ammo_fire;
        Object * gamebox;
        Object * gameover;
        Object * g_title;
        Object * r_title;
        Object * textbox;
        Object * text;
        Hang hangok;

        int Objectszam;
        float level_size;
        char level_color[30];

        float ballspeed_x[3];
        float ballspeed_y[3];
        float ballspeed;
        int ** flags;

        int life;
        int level;
        int ammo;
        int blocks;
        int score;
        bool megaball;
        int wall;
        bool grip;

        bool isCompleted;


        bool bal;
        bool jobb;

        char * levelpath;
        char objpath[50][30];
        char texpath[50][30];
        int on_board[50];
        bool play_list[8];
        bool * isSound;
        bool * isMusic;
        int * language;

        float level_x;
        float level_y;
        float level_z;

        Top * top;
        char * scorename;
};

#endif // JATEK_H
