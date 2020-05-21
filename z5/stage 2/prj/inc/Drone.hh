#pragma once

#include <string>

#include "Vector.hh"
#include "Shape.hh"
#include "Cuboid.hh"
#include "Rotor.hh"
#include "filenames.hh"

namespace DroneOpt
{
    enum pickRotor {kLeftRotor, kRightRotor};
};
class Drone
{
private:
    Vector3D _translation;
    double _angle;
    Cuboid _body;
    Rotor _leftRotor;
    Rotor _rightRotor;
public:
    Drone();
    void draw(std::string filename) const;
    void setAngle(double angle);
    double getAngle() const {return _angle;}
    void translate(const Vector3D &translation);
    Vector3D getTranslation() const {return _translation;}
    void setRotation(DroneOpt::pickRotor select, double rotation);
};