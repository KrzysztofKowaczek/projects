#include "Matrix.hh"
#include "Vector.hh"
#include <cmath>

constexpr double PI = 3.14159265;

void Matrix3D::rotationX(double angle)
{
    Matrix3D &matrix = *this;
    double rad = angle * PI / 180.0;
    matrix[0][0] = 1;
    matrix[1][1] = matrix[2][2] = cos(rad);
    matrix[1][2] = -sin(rad);
    matrix[2][1] = sin(rad);
}

void Matrix3D::rotationY(double angle)
{
    Matrix3D &matrix= *this;
    double rad = angle * PI / 180.0;
    matrix[1][1] = 1;
    matrix[0][0] = matrix[2][2] = cos(rad);
    matrix[2][0] = sin(rad);
    matrix[0][2] = -sin(rad);
}

void Matrix3D::rotationZ(double angle)
{
    Matrix3D &matrix = *this;
    double rad = angle * PI / 180.0;
    matrix[2][2] = 1;
    matrix[0][0] = matrix[1][1] = cos(rad);
    matrix[0][1] = -sin(rad);
    matrix[1][0] = sin(rad);
}