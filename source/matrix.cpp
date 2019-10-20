#include "matrix.h"


void Matrix4x4::identity()
{
    m11 = m22 = m33 = m44 = 1;
    m12 = m13 = m14 = 0;
    m21 = m23 = m24 = 0;
    m31 = m32 = m34 = 0;
    m41 = m42 = m43 = 0;
}


void Matrix4x4::transpose()
{
    auto swap = [](float& a, float& b)
    {
        float temp = a;
        a = b;
        b = temp;
    };

    swap(m12, m21);
    swap(m13, m31);
    swap(m14, m41);
    swap(m23, m32);
    swap(m24, m42);
    swap(m34, m43);
}


Matrix4x4 Matrix4x4::operator*(const Matrix4x4& rhv) const
{
    Matrix4x4 result;

    auto rowTimeCol = [](float r1, float r2, float r3, float r4, float c1, float c2, float c3, float c4)
    {
        return r1 * c1 + r2 * c2 + r3 * c3 + r4 * c4;
    };
    
    result.m11 = rowTimeCol(m11, m12, m13, m14, rhv.m11, rhv.m21, rhv.m31, rhv.m41);
    result.m12 = rowTimeCol(m11, m12, m13, m14, rhv.m12, rhv.m22, rhv.m32, rhv.m42);
    result.m13 = rowTimeCol(m11, m12, m13, m14, rhv.m13, rhv.m23, rhv.m33, rhv.m43);
    result.m14 = rowTimeCol(m11, m12, m13, m14, rhv.m14, rhv.m24, rhv.m34, rhv.m44);
    result.m21 = rowTimeCol(m21, m22, m23, m24, rhv.m11, rhv.m21, rhv.m31, rhv.m41);
    result.m22 = rowTimeCol(m21, m22, m23, m24, rhv.m12, rhv.m22, rhv.m32, rhv.m42);
    result.m23 = rowTimeCol(m21, m22, m23, m24, rhv.m13, rhv.m23, rhv.m33, rhv.m43);
    result.m24 = rowTimeCol(m21, m22, m23, m24, rhv.m14, rhv.m24, rhv.m34, rhv.m44);
    result.m31 = rowTimeCol(m31, m32, m33, m34, rhv.m11, rhv.m21, rhv.m31, rhv.m41);
    result.m32 = rowTimeCol(m31, m32, m33, m34, rhv.m12, rhv.m22, rhv.m32, rhv.m42);
    result.m33 = rowTimeCol(m31, m32, m33, m34, rhv.m13, rhv.m23, rhv.m33, rhv.m43);
    result.m34 = rowTimeCol(m31, m32, m33, m34, rhv.m14, rhv.m24, rhv.m34, rhv.m44);
    result.m41 = rowTimeCol(m41, m42, m43, m44, rhv.m11, rhv.m21, rhv.m31, rhv.m41);
    result.m42 = rowTimeCol(m41, m42, m43, m44, rhv.m12, rhv.m22, rhv.m32, rhv.m42);
    result.m43 = rowTimeCol(m41, m42, m43, m44, rhv.m13, rhv.m23, rhv.m33, rhv.m43);
    result.m44 = rowTimeCol(m41, m42, m43, m44, rhv.m14, rhv.m24, rhv.m34, rhv.m44);

    return result;
}