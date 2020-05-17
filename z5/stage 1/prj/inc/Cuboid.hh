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
    void calculateAngle(Matrix3D &matrix) const;
public:
    Cuboid();
    void setAngle(double angle) 
            {_angle = angle; while(_angle > 360) _angle -= 360;}
    double getAngle() const {return _angle;}
    Vector3D getTranslation() const {return _translation;}
    void draw(std::string filename) const;
};