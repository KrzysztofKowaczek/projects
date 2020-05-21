#include "Drone.hh"

Drone::Drone()
{
    Vector3D mountPoint;
    mountPoint[0] = -25;
    mountPoint[1] = -20;
    mountPoint[2] = 20;
    _leftRotor.setMountPoint(mountPoint);
    mountPoint[1] = 20;
    _rightRotor.setMountPoint(mountPoint);
}

void Drone::draw(std::string filename) const
{
    _body.draw(filename);
    _leftRotor.draw(filename);
    _rightRotor.draw(filename);
}

void Drone::setAngle(double angle)
{
    _angle = angle;
    while(_angle > 360) _angle -= 360;
    _body.setAngle(angle);
    _leftRotor.setAngle(angle);
    _rightRotor.setAngle(angle);
}

void Drone::translate(const Vector3D &translation)
{
    _translation = translation;
    _body.translate(translation);
    _leftRotor.translate(translation);
    _rightRotor.translate(translation);
}

void Drone::setRotation(DroneOpt::pickRotor select, double rotation)
{
    switch(select)
    {
    case DroneOpt::kRightRotor:
        _rightRotor.setRotation(rotation);
        break;
    case DroneOpt::kLeftRotor:
        _leftRotor.setRotation(rotation);
        break;
    }
}