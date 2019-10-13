#ifndef __VECTOR_H__
#define __VECTOR_H__

class Vector
{
public:
    float x;
    float y;
    float z;

    Vector(float inX, float inY, float inZ) : x(inX), y(inY), z(inZ) {}
    Vector() : Vector(0, 0, 0) {}
};

#endif

