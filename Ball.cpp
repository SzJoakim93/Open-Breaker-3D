#include "Ball.h"

Ball::Ball(Object * _ball, bool _active)
{
    this->ballObj = _ball;
    active = _active;
    setDefaults();
}

Ball::~Ball()
{
    delete ballObj;
}

void Ball::setDefaults(int level_size, Object * padle)
{
    ballspeed = 0;
    ballspeed_x = 0.5;
    ballspeed_y = 0.5;
    ballObj->settx(padle->gettx());
    ballObj->settz(-0.32+level_size);
}

void Ball::cloneBall(Ball * original, char side)
{
    ballObj->settx(original->getObj()->gettx());
    ballObj->settz(original->getObj()->gettz());
    ballspeed_x = side == 0 ? original->ballspeed_x+0.1 : original->ballspeed_x-0.1;
    ballspeed_y = side == 0 ? original->ballspeed_y-0.1 : original->ballspeed_y+0.1;
}

bool Ball::pongFromPaddle(Object * padle)
{
    if (ballObj->gettx() < padle->gettx() - padle->getsx() + padle->getsx()/6)
    {
        ballspeed_x = 0.7;
        ballspeed_y = 0.3;
    }
    else if (ballObj->gettx() < padle->gettx() - padle->getsx() + 2*padle->getsx()/6)
    {
        ballspeed_x = 0.6;
        ballspeed_y = 0.4;
    }
    else if (ballObj->gettx() < padle->gettx() - padle->getsx() + 3*padle->getsx()/6)
    {
        ballspeed_x = 0.5;
        ballspeed_y = 0.5;
    }

    else if (ballObj->gettx() < padle->gettx() - padle->getsx() + 4*padle->getsx()/6)
    {
        ballspeed_x = 0.4;
        ballspeed_y = 0.6;
    }

    else if (ballObj->gettx() < padle->gettx() - padle->getsx() + 5*padle->getsx()/6)
    {
        ballspeed_x = 0.3;
        ballspeed_y = 0.7;
    }

    else if (ballObj->gettx() < padle->gettx() - padle->getsx() + 6*padle->getsx()/6)
    {
        ballspeed_x = 0.1;
        ballspeed_y = 0.9;

    }
    else if (ballObj->gettx() < padle->gettx() - padle->getsx() + 7*padle->getsx()/6)
    {
        ballspeed_x = -0.1;
        ballspeed_y = 0.9;
    }
    else if (ballObj->gettx() < padle->gettx() - padle->getsx() + 8*padle->getsx()/6)
    {
        ballspeed_x = -0.3;
        ballspeed_y = 0.7;
    }
    else if (ballObj->gettx() < padle->gettx() - padle->getsx() + 9*padle->getsx()/6)
    {
        ballspeed_x = -0.4;
        ballspeed_y = 0.6;
    }

    else if (ballObj->gettx() < padle->gettx() - padle->getsx() + 10*padle->getsx()/6)
    {
        ballspeed_x = -0.5;
        ballspeed_y = 0.5;
    }

    else if (ballObj->gettx() < padle->gettx() - padle->getsx() + 11*padle->getsx()/6)
    {
        ballspeed_x = -0.6;
        ballspeed_y = 0.4;
    }
    else
    {
        ballspeed_x = -0.7;
        ballspeed_y = 0.3;
    }

}

bool Ball::pongFromBorder(float level_size)
{
    if (ballObj->gettx() > 0.45 + level_size && ballspeed_x < 0.0 || ballObj->gettx() < 0.55 - level_size && ballspeed_x > 0.0)
    {
        ballspeed_x *= -1.0;
        if (*isSound)
            sounds.play_sound(0, -1);
    }


    if (ballObj->gettz() < -0.15 - level_size || wall > 0 && ballObj->gettz() > -0.25 + level_size)
    {
        ballspeed_y *= -1.0;
        if (*isSound)
            sounds.play_sound(0, -1);
    }
}

void Ball::moving()
{
    ballObj->trans_horizontal(ballspeed_x*ballspeed);
    ballObj->trans_vertical(ballspeed_y*ballspeed);
}

bool Ball::collision(Object * obj)
{
    return (ballObj->gettx() + ballObj->getsx() > obj->gettx() - obj->getsx() && ballObj->gettx() - ballObj->getsx() < obj->gettx() + obj->getsx() &&
    ballObj->gettz() + ballObj->getsz() > obj->gettz() - obj->getsz() && ballObj->gettz() + ballObj->getsz() < obj->gettz() - obj->getsz());
}

bool Ball::collision_front(Object * obj)
{
    return ballObj->gettx() + ballObj->getsx() > obj->gettx() - obj->getsx() && ballObj->gettx() - ballObj->getsx() < obj->gettx() + obj->getsx() &&
    ballObj->gettz() + ballObj->getsz() > obj->gettz() - obj->getsz() && ballObj->gettz() + ballObj->getsz() < obj->gettz() - obj->getsz() + 0.02;
}

bool Ball::collision_back(Object * obj)
{
    return ballObj->gettx() + ballObj->getsx() > obj->gettx() - obj->getsx() && ballObj->gettx() - ballObj->getsx() < obj->gettx() + obj->getsx() &&
    ballObj->gettz() - ballObj->getsz() < obj->gettz() + obj->getsz() && ballObj->gettz() - ballObj->getsz() > obj->gettz() + obj->getsz() - 0.02;
}

bool Ball::collision_left(Object * obj)
{
    return ballObj->gettz() + ballObj->getsz() > obj->gettz() - obj->getsz() && ballObj->gettz() - ballObj->getsz() < obj->gettz() + obj->getsz() &&
    ballObj->gettx() - ballObj->getsx() < obj->gettx() + obj->getsx() && ballObj->gettx() - ballObj->getsx() > obj->gettx() + obj->getsx() - 0.02;
}

bool Ball::collision_right(Object * obj)
{
    return ballObj->gettz() + ballObj->getsz() > obj->gettz() - obj->getsz() && ballObj->gettz() - ballObj->getsz() < obj->gettz() + obj->getsz() &&
    ballObj->gettx() + ballObj->getsx() > obj->gettx() - obj->getsx() && ballObj->gettx() + ballObj->getsx() < obj->gettx() - obj->getsx() + 0.02;
     
}

void Ball::reverseDir_X()
{
    ballspeed_x *=-1;
}

void Ball::reverseDir_X()
{
    ballspeed_y *=-1;
}

void Ball::reverseDir_Y()
{
    ballspeed_y *=-1;
}

Object * Ball::getObj()
{
    return ballObj;
}

bool Ball::isActive()
{
    return active;
}

bool Ball::isLaunched()
{
    return ballspeed != 0.0f;
}

void Ball::setSpeed(const float x)
{
    ballspeed = x;
}