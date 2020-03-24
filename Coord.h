#ifndef COORD_H
#define COORD_H

typedef struct eCoord3f
{
    float x;
    float y;
    float z;
    eCoord3f() {}
    eCoord3f(float _x, float _y, float _z)
        : x(_x), y(_y), z(_z) {}
};

typedef struct eCoord3i
{
    int x;
    int y;
    int z;
};

typedef struct eCoord2f
{
    float x;
    float y;
    eCoord2f() {}
    eCoord2f(float _x, float _y)
        : x(_x), y(_y) {}
};

#endif //Coord_H