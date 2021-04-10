#ifndef JATEK_H
#define JATEK_H

#include <dirent.h>
#include <cstring>
#include <cstdio>

#include "State.h"
#include "UI_Label.h"
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
        Game(Appsettings * appsettings, SDL_Event * event, Uint8* keystates, char * level_path, Top * top,
        void (*backToMenu)(void*),void* application);
        virtual ~Game();
        virtual void rendering();
        virtual void hanldeSDLEvents();
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
        inline void starEvents();
        inline void end_level();
        inline void ball_events();
        inline void ballCollisions();
        inline void ammoEvents();
        inline void bonusEvents();
        inline void increaseScore(const int x);
        inline void increaseLife(const int x);
        inline void increaseAmmo(const int x);
        Level * level;
        Ball * balls[3];
        Object * stars[3];
        
        UI ** titles;
        UI_Label * life_title;
        UI_Label * ammo_title;
        UI_Label * score_title;
        UI_Label * level_title;
        UI_Label * block_title;
        UI_Label * best_title;
        UI * textbox;
        UI * text;
        UI * gameover;
        UI * g_title;
        UI * r_title;
        UI * gamebox;

        Object * padle;
        Object ** bonuses;
        Object * ammo_fire;

        Sound sounds;

        Player * player;

        bool left_key_pressed;
        bool right_key_pressed;
        bool play_list[8];

        Top * top;
        char * scorename;

        void (*backToMenu)(void*);
        void * application;
};

#endif // JATEK_H
