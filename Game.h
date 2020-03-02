#ifndef JATEK_H
#define JATEK_H

#include <dirent.h>
#include <cstring>
#include <cstdio>

#include "Ball.h"
#include "Player.h"
#include "Block.h"
#include "Object.h"
#include "Sound.h"
#include "vector.h"

#define MAX_LEVEL 20

typedef struct Top
{
    int score;
    char name[20];
} Top;

class Game
{
    public:
        Game(char * level_path, Top * top, char * scorename, int * width, int * height, int * language);
        ~Game();
        void load(char * path);
        void esemenyek(int & jatekresz);
        void leftKeyDown();
        void rightKeyDown();
        void leftKeyUp();
        void rightKeyUp();
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
        void setBallSpeed(const float x);
    protected:
    private:
        void print(int x, Object & Object);
        vector<Block*> level_objects;
        Ball * balls[3];
        Object * stars[3];
        Object * aljzat;
        Object * fal1;
        Object * fal2;
        Object * fal3;
        Object * fal4;
        Object * padle;
        Object ** titles;
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
        Sound sounds;

        float level_size;
        char level_color[30];

        int level;
        int blocks;

        Player * player;

        bool isCompleted;


        bool left_key_pressed;
        bool right_key_pressed;

        char * levelpath;
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
