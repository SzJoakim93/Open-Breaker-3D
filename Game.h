#ifndef JATEK_H
#define JATEK_H

#include <dirent.h>
#include <cstring>
#include <cstdio>

#include "State.h"
#include "UI.h"
#include "Appsettings.h"
#include "Ball.h"
#include "Player.h"
#include "Block.h"
#include "Object.h"
#include "Sound.h"
#include "Level.h"
#include "vector.h"

#define MAX_LEVEL 20

typedef struct Top
{
    int score;
    char name[20];
} Top;

class Game : public State
{
    public:
        Game(Appsettings * appsettings, SDL_Event * event, Uint8* keystates, char * level_path, Top * top);
        virtual ~Game();
        virtual void rendering();
        virtual void handleEvents();
        void load(char * path);
        void enter();
        void stop();
        void start(const int & level);
        void launch();
        int getLife();
        int getScore();
        bool getCompleted();
        void setBallSpeed(const float x);
        void hitBonusObject(Block * obj);
        void hitNormalObject(Block * obj, Ball * ball);
    protected:
    private:
        inline void print(int x, Object & Object);
        inline void starEvents();
        inline void end_level();
        inline void ball_events();
        inline void ballCollisions();
        inline void ammoEvents();
        inline void bonusEvents();
        Level * level;
        Ball * balls[3];
        Object * stars[3];
        
        UI ** titles;
        UI * life_title;
        UI * ammo_title;
        UI * score_title;
        UI * level_title;
        UI * block_title;
        UI * best_title;
        UI * textbox;
        UI * text;

        Object * padle;
        Object ** bonuses;
        Object * ammo_fire;
        Object * gamebox;
        Object * gameover;
        Object * g_title;
        Object * r_title;
        
        Sound sounds;

        Player * player;

        bool left_key_pressed;
        bool right_key_pressed;
        bool play_list[8];

        Top * top;
        char * scorename;
};

#endif // JATEK_H
