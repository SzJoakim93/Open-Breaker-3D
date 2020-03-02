#ifndef BLOCK_H
#define BLOCK_H

#include "Object.h"
#include "vector.h"

class Block
{
private:
    Object * blockObj;
    int * flags;
public:
    Block(Object * _block, int * _flags);
    ~Block();
    void hit();
    void moving();
    void reverse_direction();
    Object * getObj();
    bool isNormal();
    bool isBonus();
    bool isSolid();
    bool isMoving();
    bool isActive();
    bool destroyed();
    void gravityEvents(vector<Block*> & obj_list);
};

#endif //Block_H