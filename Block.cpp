#include "Block.h"

Block::Block(Object * _block, int * _flags)
{
    this->blockObj = _block;
    this->flags = _flags;
}

Block::~Block()
{
    delete blockObj;
    delete [] flags;
}

void Block::hit()
{
    flags[0]--;
}

Object * Block::getObj()
{
    return blockObj;
}

bool Block::isNormal()
{
    return flags[0] > 0 && flags[0] < 9;
}

bool Block::isBonus()
{
    return flags[0] % 10 == 9 || flags[0] == -1;
}

bool Block::isSolid()
{
    return false;
}

bool Block::isMoving()
{
    return flags[0] == -2;
}

void Block::moving()
{
    float t_begin = flags[1]/100.0;
    float t_end = flags[2]/100.0;
    float moving = flags[3]/1000.0;

    blockObj->trans_horizontal(moving);
    if (blockObj->gettx() < t_begin || blockObj->gettx() > t_end)
        flags[3] *= -1;
}

void Block::reverse_direction()
{
    flags[3] *= -1;
}

bool Block::isActive()
{
    return flags[0] != 0;
}

bool Block::destroyed()
{
    return flags[0] == 0;
}

void Block::gravityEvents(vector<Block*> & obj_list)
{
    if (blockObj->getGravityRange() > 0.0)
    {
        for (int j=1; flags[j] > -1 && j<10; j++)
            obj_list[flags[j]]->getObj()->trans_lengthical(-0.001);

        blockObj->trans_gravity(-0.0005);

        if (blockObj->getGravityRange() < 0.0)
            for (int j=1; flags[j] > -1 && j<9; j++)
                obj_list[flags[j]]->flags[0] -= 10;
    }
}

/*
if (level_objects[i]->getGravityRange() > 0.0)
{
    for (int j=1; flags[i][j] > -1 && j<10; j++)
        level_objects[flags[i][j]]->trans_lengthical(-0.001);

    level_objects[i]->getObj()->trans_gravity(-0.0005);

    if (level_objects[i]->getObj()->getGravityRange() < 0.0)
        for (int j=1; flags[i][j] > -1 && j<9; j++)
            flags[flags[i][j]][0] -= 10;
}
*/