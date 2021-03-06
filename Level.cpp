#include "Level.h"

Level::Level(const int level)
{
    wall = 0;
    this->level = level;
    levelpath = new char [30];
    sprintf(levelpath, "Levels/L%d.txt", level);
    load(levelpath);

    delete levelpath;

    aljzat = new Object(0.5f, -0.3f, -0.2f, //koordinatak
                      0, 0, 0, //elforgatas
                      size, 1.0f, size, //atmeretezes
                      NULL, color, "rectangle");

    fal1 = new Object(0.5f + size, -0.27f, -0.2, //koordinatak
                    0, 0, 0, //elforgatas
                    0.01f, 0.025f, size, //atmeretezes
                    NULL, color, "Objects/cube.obj");

    fal2 = new Object(0.5 - size, -0.27, -0.2, //koordinatak
                    0, 0, 0, //elforgatas
                    0.01f, 0.025f, size, //atmeretezes
                    NULL, color, "Objects/cube.obj");

    fal3 = new Object(0.5f, -0.27f, -0.2f - size, //koordinatak
                    0, 90, 0, //elforgatas
                    0.01f, 0.025f, size, //atmeretezes
                    NULL, color, "Objects/cube.obj");

    fal4 = new Object(0.5f, -0.27f, -0.2f + size, //koordinatak
                    0, 90, 0, //elforgatas
                    0.01f, 0.025f, size, //atmeretezes
                    NULL, color, "Objects/cube.obj");

    completed = false;
}

Level::~Level()
{
    for (int i=0; i<level_objects.size(); i++)
        delete level_objects[i];
    level_objects.clear();

    delete fal1;
    delete fal2;
    delete fal3;
    delete fal4;

    delete aljzat;
}

void Level::load(char * path)
{
    FILE * file = fopen(path, "r");
    fscanf(file, "%f %s", &size, color);
    level_x = -0.8f+size*2.0f/1.5f;
    level_y = 0.3f-size*2.0f;
    level_z = 0.3f-size*2.0f;

    blocks=0;

    while(!feof(file))
    {
        float tx;
        float ty;
        float tz;
        float sx;
        float sy;
        float sz;
        char texture[30];
        char obj[30];
        int r;
        int * new_flag = new int [10];
            
        fscanf(file, "%f %f %f %f %f %f %d %s %s %d %d %d %d %d %d %d %d %d %d", &tx, &ty, &tz, &sx, &sy, &sz, &r, texture, obj, &new_flag[0], &new_flag[1], &new_flag[2], &new_flag[3], &new_flag[4], &new_flag[5], &new_flag[6], &new_flag[7], &new_flag[8], &new_flag[9]);
        level_objects.insert(new Block(new Object(tx, ty, tz, //koordinatak
                             0, r, 0, //elforgatas
                             sx, sy, sz, //atmeretezes
                             NULL, texture, obj), new_flag));

        if (new_flag[0] != -2)
            blocks++;
    }

    fclose(file);
}

void Level::rendering()
{
    for (int i=0; i<level_objects.size(); i++)
        level_objects[i]->getObj()->rendering();

    aljzat->rendering();
    fal1->rendering();
    fal2->rendering();
    fal3->rendering();
    if (wall > 0 && wall < 20 || wall > 40 && wall < 60 || wall > 80 && wall < 100 || wall > 120)
        fal4->rendering();
}

void Level::cameraAnimation()
{
    if (Object::getCX() < level_x - 0.2)
        Object::setcx(Object::getCX() + 0.2);

    if (Object::getCY() < level_y - 0.2)
        Object::setcy(Object::getCY() + 0.2);

    if (Object::getCZ() < level_z - 0.2)
        Object::setcz(Object::getCZ() + 0.2);
}


void Level::events()
{
    for (int i=0; i<level_objects.size(); i++)
    {
        if (level_objects[i]->isBonus())
        {
            level_objects[i]->getObj()->rotateY(1);
        }
        else if (level_objects[i]->isMoving())
        {
            level_objects[i]->moving();    
        }

        level_objects[i]->gravityEvents(level_objects);
    }

    if (wall > 0)
        wall--;
}

void Level::manageCollision(Ball * ball, Object * ammo)
{
    
}

void Level::decreaseBlock()
{
    blocks --;
}

const float Level::getSize()
{
    return size;
}

const int Level::getBlockNum()
{
    return blocks;
}

const int Level::getNum()
{
    return level;
}

const vector<Block*> & Level::getObjs()
{
    return level_objects;
}

const bool Level::isCompleted()
{
    return blocks < 1;
}

const bool Level::isWall()
{
    return wall > 0;
}

void Level::setWall(const int x)
{
    wall = x;
}