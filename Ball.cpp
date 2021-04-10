#include "Ball.h"

char Ball::active_balls = 0;
Sound * Ball::sounds;

Ball::Ball(Object * _ball, bool _active)
{
    this->ballObj = _ball;
    active = _active;
    setDefaults();

    if (_active)
        active_balls++;
}

Ball::~Ball()
{
    delete ballObj;
    active_balls--;
}

void Ball::setActive(const bool _active)
{
    if (active != _active)
    {
        if (_active)
            active_balls++;
        else
            active_balls--;
    }

    active = _active;

}

void Ball::setDefaults()
{
    ballspeed = 0;
    ballspeed_x = 0.5;
    ballspeed_y = 0.5;
}

void Ball::cloneBall(Ball * original, char side)
{
    active = true;
    active_balls++;
    ballObj->setTX(original->getObj()->getTX());
    ballObj->setTZ(original->getObj()->getTZ());
    ballspeed_x = side == 0 ? original->ballspeed_x+0.1 : original->ballspeed_x-0.1;
    ballspeed_y = side == 0 ? original->ballspeed_y-0.1 : original->ballspeed_y+0.1;
    ballspeed = original->ballspeed;
}

void Ball::pongFromPaddle(Object * padle)
{
    if (ballObj->getTX() < padle->getTX() - padle->getSX() + padle->getSX()/6)
    {
        ballspeed_x = 0.7;
        ballspeed_y = 0.3;
    }
    else if (ballObj->getTX() < padle->getTX() - padle->getSX() + 2*padle->getSX()/6)
    {
        ballspeed_x = 0.6;
        ballspeed_y = 0.4;
    }
    else if (ballObj->getTX() < padle->getTX() - padle->getSX() + 3*padle->getSX()/6)
    {
        ballspeed_x = 0.5;
        ballspeed_y = 0.5;
    }

    else if (ballObj->getTX() < padle->getTX() - padle->getSX() + 4*padle->getSX()/6)
    {
        ballspeed_x = 0.4;
        ballspeed_y = 0.6;
    }

    else if (ballObj->getTX() < padle->getTX() - padle->getSX() + 5*padle->getSX()/6)
    {
        ballspeed_x = 0.3;
        ballspeed_y = 0.7;
    }

    else if (ballObj->getTX() < padle->getTX() - padle->getSX() + 6*padle->getSX()/6)
    {
        ballspeed_x = 0.1;
        ballspeed_y = 0.9;

    }
    else if (ballObj->getTX() < padle->getTX() - padle->getSX() + 7*padle->getSX()/6)
    {
        ballspeed_x = -0.1;
        ballspeed_y = 0.9;
    }
    else if (ballObj->getTX() < padle->getTX() - padle->getSX() + 8*padle->getSX()/6)
    {
        ballspeed_x = -0.3;
        ballspeed_y = 0.7;
    }
    else if (ballObj->getTX() < padle->getTX() - padle->getSX() + 9*padle->getSX()/6)
    {
        ballspeed_x = -0.4;
        ballspeed_y = 0.6;
    }

    else if (ballObj->getTX() < padle->getTX() - padle->getSX() + 10*padle->getSX()/6)
    {
        ballspeed_x = -0.5;
        ballspeed_y = 0.5;
    }

    else if (ballObj->getTX() < padle->getTX() - padle->getSX() + 11*padle->getSX()/6)
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

bool Ball::pongFromBorder(float level_size, const bool wall)
{
    if ((ballObj->getTX() > 0.45 + level_size && ballspeed_x < 0.0) || (ballObj->getTX() < 0.55 - level_size && ballspeed_x > 0.0))
    {
        ballspeed_x *= -1.0;
        sounds->play_sound(0, -1);
    }


    if ((ballObj->getTZ() < -0.15 - level_size && ballspeed_y > 0.0) || (wall > 0 && ballObj->getTZ() > -0.25 + level_size && ballspeed_y < 0.0))
    {
        ballspeed_y *= -1.0;
        sounds->play_sound(0, -1);
    }
}

void Ball::moving()
{
    ballObj->translateX(ballspeed_x*ballspeed);
    ballObj->translateZ(ballspeed_y*ballspeed);
}

int Ball::getSpeed()
{
    return ballspeed;
}

bool Ball::collision(Object * obj)
{
    return ballObj->getTY() > obj->getTY() - obj->getSY() &&
        ballObj->getTX() + ballObj->getSX() > obj->getTX() - obj->getSX() && ballObj->getTX() - ballObj->getSX() < obj->getTX() + obj->getSX() &&
        ballObj->getTZ() + ballObj->getSZ() > obj->getTZ() - obj->getSZ() && ballObj->getTZ() - ballObj->getSZ() < obj->getTZ() + obj->getSZ();
}

bool Ball::collision_front(Object * obj)
{
    return ballObj->getTX() + ballObj->getSX() > obj->getTX() - obj->getSX() && ballObj->getTX() - ballObj->getSX() < obj->getTX() + obj->getSX() &&
    ballObj->getTZ() + ballObj->getSZ() > obj->getTZ() - obj->getSZ() && ballObj->getTZ() + ballObj->getSZ() < obj->getTZ() - obj->getSZ() + 0.02;
}

bool Ball::collision_back(Object * obj)
{
    return ballObj->getTX() + ballObj->getSX() > obj->getTX() - obj->getSX() && ballObj->getTX() - ballObj->getSX() < obj->getTX() + obj->getSX() &&
    ballObj->getTZ() - ballObj->getSZ() < obj->getTZ() + obj->getSZ() && ballObj->getTZ() - ballObj->getSZ() > obj->getTZ() + obj->getSZ() - 0.02;
}

bool Ball::collision_left(Object * obj)
{
    return ballObj->getTZ() + ballObj->getSZ() > obj->getTZ() - obj->getSZ() && ballObj->getTZ() - ballObj->getSZ() < obj->getTZ() + obj->getSZ() &&
    ballObj->getTX() - ballObj->getSX() < obj->getTX() + obj->getSX() && ballObj->getTX() - ballObj->getSX() > obj->getTX() + obj->getSX() - 0.02;
}

bool Ball::collision_right(Object * obj)
{
    return ballObj->getTZ() + ballObj->getSZ() > obj->getTZ() - obj->getSZ() && ballObj->getTZ() - ballObj->getSZ() < obj->getTZ() + obj->getSZ() &&
    ballObj->getTX() + ballObj->getSX() > obj->getTX() - obj->getSX() && ballObj->getTX() + ballObj->getSX() < obj->getTX() - obj->getSX() + 0.02;
     
}

void Ball::setPositiveDir_X()
{
    if (ballspeed_x < 0.0f)
        ballspeed_x *=-1;
}

void Ball::setNegativeDir_X()
{
    if (ballspeed_x > 0.0f)
        ballspeed_x *=-1;
}

void Ball::setPositiveDir_Y()
{
    if (ballspeed_y < 0.0f)
    ballspeed_y *=-1;
}

void Ball::setNegativeDir_Y()
{
    if (ballspeed_y > 0.0f)
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

void Ball::increaseSpeed(const float x)
{
    if (ballspeed > -0.03);
        ballspeed += x;
}

char Ball::getActiveBalls()
{
    return active_balls;
}

void Ball::setSounds(Sound * _sounds)
{
    sounds = _sounds;
}