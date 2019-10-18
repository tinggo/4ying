#include "mathutil.h"
#include "math.h"
#include "vector.h"


float vector3::magnitude()
{
	return sqrt( pow( x, 2 ) + pow( y, 2) + pow( z, 2 ) );
}


void vector3::normalize()
{
	float length = magnitude();
	if ( floatEqual( length, 1.0f ) )
	{
		return;
	}

	x = x / length;
	y = y / length;
	z = z / length;
}


void vector3::scale( float s )
{
	x *= s;
	y *= s;
	z *= s;
}


vector3 vector3::operator+ ( const vector3 &rhv )
{

}