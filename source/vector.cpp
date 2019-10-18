#include "mathutil.h"
#include "math.h"
#include "vector.h"


vector3::vector3()
{
    x = y = z = 0.0f;
}


vector3::vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}


void vector3::normalize()
{
    float length = magnitude();
    if (floatEqual(length, 1.0f))
    {
        return;
    }

    x = x / length;
    y = y / length;
    z = z / length;
}


void vector3::zero()
{
    x = y = z = 0.0f;
}


float vector3::magnitude() const
{
	return static_cast<float>( sqrt( pow( x, 2 ) + pow( y, 2) + pow( z, 2 ) ) );
}


vector3 vector3::operator+ ( const vector3 &rhv ) const
{
    vector3 result;
    result.x = x + rhv.x;
    result.y = y + rhv.y;
    result.z = z + rhv.z;
    return result;
}


vector3 vector3::operator- ( const vector3& rhv ) const
{
    vector3 result;
    result.x = x - rhv.x;
    result.y = y - rhv.y;
    result.z = z - rhv.z;
    return result;
}


vector3 vector3::operator*(const float& rhv) const
{
    vector3 result;
    result.x = x * rhv;
    result.y = y * rhv;
    result.z = z * rhv;
    return result;
}


float vector3::operator* ( const vector3 &rhv ) const
{
    return x * rhv.x + y * rhv.y + z * rhv.z;
}


vector3 vector3::crossProduct( const vector3& rhv ) const
{
    vector3 result;
    result.x = y * rhv.z - z * rhv.y;
    result.y = z * rhv.x - x * rhv.z;
    result.z = x * rhv.y - y * rhv.x;
    return result;
}


vector3 operator*(const float& lhv, const vector3& rhv)
{
    vector3 result;
    result.x = lhv * rhv.x;
    result.y = lhv * rhv.y;
    result.z = lhv * rhv.z;
    return result;
}