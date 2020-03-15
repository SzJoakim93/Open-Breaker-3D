#ifndef LEVEL_H
#define LEVEL_H

#include "Block.h"
#include "Ball.h"

class Level
{
private:
    vector<Block*> level_objects;
    Object * aljzat;
    Object * fal1;
    Object * fal2;
    Object * fal3;
    Object * fal4;
    float size;
    char color[30];
    int level;
    int blocks;
    bool completed;
    char * levelpath;
    float level_x;
    float level_y;
    float level_z;
    int wall;

public:
    Level(const int level);
    ~Level();
    void load(char * path);
    void rendering();
    void events();
    void cameraAnimation();
    void manageCollision(Ball * ball, Object * ammo);
    void decreaseBlock();
    void setWall(const int x);
    const float getSize();
    const int getBlockNum();
    const int getNum();
    const vector<Block*> & getObjs();
    const bool isCompleted();
    const bool isWall();
};

#endif // LEVEL_H