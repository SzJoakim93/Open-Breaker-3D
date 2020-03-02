#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    int life;
    int ammo;
    int score;
    bool megaball;
    int wall;
    bool grip;
public:
    Player(/* args */);
    ~Player();
    void resetGame();
    void resetLevel();
    void wallEvent();
    int getLife();
    int getScore();
    int getAmmo();
    bool needRenderWall();
    bool isWall();
    bool isGrip();
    void increaseScore(const int x);
    void increaseLife(const int x);
    void decreaseLife();
    void increaseAmmo(const int x);
    void decreaseAmmo();
    void setGrip(const bool x);
    void setMegaBall(const bool x);
    void setWall(const int x);
};

#endif // Player_H