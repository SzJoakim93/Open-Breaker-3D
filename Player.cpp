#include "Player.h"

Player::Player(/* args */)
{
    resetGame();
    resetLevel();
}

Player::~Player()
{
}

void Player::resetGame()
{
    life = 3;
    ammo = 10;
    score = 0;
}

void Player::resetLevel()
{
    megaball = false;
    wall = 0;
    grip = false;
}

void Player::wallEvent()
{
    if (wall > 0)
        wall--;
}

int Player::getLife()
{
    return life;
}

int Player::getScore()
{
    return score;
}

int Player::getAmmo()
{
    return ammo;
}

int Player::isMegaball()
{
    return megaball;
}

bool Player::needRenderWall()
{
    return wall > 0 && wall < 20 || wall > 40 && wall < 60 || wall > 80 && wall < 100 || wall > 120;
}

bool Player::isWall()
{
    return wall > 0;
}

bool Player::isGrip()
{
    return grip;
}

void Player::increaseScore(const int x)
{
    score += x;
}

void Player::decreaseLife()
{
    life--;
}

void Player::increaseLife(const int x)
{
    life += x;
}

void Player::increaseAmmo(const int x)
{
    ammo += x;
}

void Player::decreaseAmmo()
{
    ammo--;
}

void Player::setGrip(const bool x)
{
    grip = x;
}

void Player::setMegaBall(const bool x)
{
    megaball = x;
}

void Player::setWall(const int x)
{
    wall = x;
}