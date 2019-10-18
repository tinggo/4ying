#ifndef __VECTOR_H__
#define __VECTOR_H__

class vector3
{
public:
    float x;
    float y;
    float z;

	void normalize	  ();
	void scale        ( float s );

	float magnitude();

	vector3 operator+ ( const vector3 &rhv );
	vector3 operator- ( const vector3 &rhv );
	vector3 product   ( const vector3 &rhv );
	vector3 cross     ( const vector3 &rhv );
};

#endif

