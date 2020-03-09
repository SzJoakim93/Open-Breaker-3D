#ifndef BALL_H
#define BALL_H

#include "Object.h"
#include "Sound.h"

class Ball
{
private:
    bool active;
    Object * ballObj;
    float ballspeed_x;
    float ballspeed_y;
    float ballspeed;
    static char active_balls;
public:
    Ball(Object * _ball, bool _active);
    ~Ball();
    void activate();
    void setDefaults();
    void cloneBall(Ball * original, char side);
    void pongFromPaddle(Object * padle);
    bool pongFromBorder(const float level_size, const bool wall);
    void moving();
    int getSpeed();
    bool collision(Object * obj);
    bool collision_front(Object * obj);
    bool collision_back(Object * obj);
    bool collision_left(Object * obj);
    bool collision_right(Object * obj);
    void reverseDir_X();
    void reverseDir_Y();
    Object * getObj();
    bool isActive();
    bool isLaunched();
    void setSpeed(const float x);
    void incativate();
    void increaseSpeed(const float x);
    static char getActiveBalls();
};

#endif // Ball_H