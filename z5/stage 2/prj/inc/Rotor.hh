#pragma once

#include <string>

#include "Shape.hh"
#include "Vector.hh"

class Rotor: public Shape
{
private:
    double _angle;
    double _rotation;
    Vector3D _mountPoint;
public:
    Rotor();
    virtual void draw(std::string filename) const override;
    void setAngle(double angle) 
                {_angle = angle; while(_angle > 360) _angle -= 360;}
    double getAngle() const {return _angle;}
    void setRotation(double rotation) 
                {_rotation = rotation; while(_rotation > 360) _rotation -= 360;}
    double getRotation() const {return _rotation;}
    void setMountPoint(const Vector3D &mountPoint) {_mountPoint = mountPoint;}
    Vector3D getMountPoint() const {return _mountPoint;}
    virtual std::string getName() const override {return "rotor";}
};