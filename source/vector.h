#ifndef __VECTOR_H__
#define __VECTOR_H__

class vector3
{
public:
    float x;
    float y;
    float z;

    vector3();
    vector3(float x, float y, float z);

	void normalize();
    void zero();
    float magnitude() const;	

    vector3 operator+ (const vector3& rhv) const;
    vector3 operator- (const vector3& rhv) const;
    vector3 operator* (const float& rhv) const;
    float operator* (const vector3& rhv) const;

    vector3 crossProduct(const vector3& rhv) const;
};

vector3 operator*( const float &lhv, const vector3 &rhv );

#endif