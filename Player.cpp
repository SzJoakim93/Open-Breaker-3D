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
    grip = false;
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

bool Player::isGrip()
{
    return grip;
}

void Player::increaseScore(const int x)
{
    score += x;
}

void Player::increaseLife(const int x)
{
    life += x;
}

void Player::increaseAmmo(const int x)
{
    ammo += x;
}

void Player::setGrip(const bool x)
{
    grip = x;
}

void Player::setMegaBall(const bool x)
{
    megaball = x;
}
