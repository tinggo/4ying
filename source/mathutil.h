#ifndef __MATHUTIL_H__
#define __MATHUTIL_H__
#include "math.h"


constexpr float ELAPSE = 0.000001f;


template<typename T1, typename T2>
inline bool floatEqual( T1 a, T2 b )
{
	return Math.abs( a, b ) < ELAPSE;
}
#endif
