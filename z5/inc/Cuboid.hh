#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include "Shape.hh"
#include "Vector.hh"
#include "Matrix.hh"

const std::string kModelCuboid("solid/model.dat");

class Cuboid : public Shape
{
    double _angle;
    void calculateAngle(Matrix2D &matrix) const;
public:
    Cuboid();
    void setAngle(double angle) {_angle = angle;}
    void translate(const Vector3D &trans) {_translation = trans;}
    void draw(std::string filename) const;
};

Vector3D operator*(Vector3D Vector, const Matrix2D &matrix);