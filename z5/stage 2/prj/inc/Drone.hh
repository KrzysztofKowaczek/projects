#pragma once

#include <string>

#include "Shape.hh"
#include "Cuboid.hh"
#include "Rotor.hh"
#include "filenames.hh"

namespace DroneOpt
{
    enum pickRotor {kLeftRotor, kRightRotor};
};
class Drone: public Shape
{
private:
    double _angle;
    Cuboid _body;
    Rotor _leftRotor;
    Rotor _rightRotor;
public:
    Drone();
    virtual void draw(std::string filename) const override;
    void setAngle(double angle);
    double getAngle() const {return _angle;}
    void translate(const Vector3D &translation);
    void setRotation(DroneOpt::pickRotor select, double rotation);
};