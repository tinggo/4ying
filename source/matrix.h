#ifndef __MATRIX_H__
#define __MATRIX_H__

class Matrix4x4
{
public:
    float m11, m12, m13, m14;
    float m21, m22, m23, m24;
    float m31, m32, m33, m34;
    float m41, m42, m43, m44;

    void identity();
    void transpose();

    Matrix4x4 operator*(const Matrix4x4 &rhv) const;
};

#endif

