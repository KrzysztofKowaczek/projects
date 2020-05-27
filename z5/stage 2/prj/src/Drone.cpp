#include "Drone.hh"
#include "Vector.hh"

#include <vector>
#include <chrono>
#include <thread>

using namespace std;

chrono::duration<int, milli> timespan(20); 

constexpr double PI = 3.14159265;

Drone::Drone(): _outline{60}
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

bool Drone::checkCollisions() const
{
    Vector3D centerOutline(_outline/2);
    centerOutline[2] -= 20; //Dron na poczatku jest o 20 wyzej od srodka ukladu
    Vector3D minValues = _translation - centerOutline;
    Vector3D maxValues = _translation + _outline - centerOutline;
    Vector3D point;
    int overlap;
    for(unsigned i = 0; i < _scene.objects.size(); ++i)
        for(unsigned j = 0; j < _scene.objects[i]->getPoints().size(); ++j)
        {
            point = _scene.objects[i]->getPoints()[j];
            for(unsigned k = 0; k < 3; ++k)
                if((point[k] < maxValues[k]) && (point[k] > minValues[k]))
                    overlap += 1;
            if(overlap == 3)
            {
                cerr << "Wykryto kolizje z: " << _scene.objects[i]->getName() 
                        << endl;
                return true;
            }
            overlap = 0;
        }

    return false;
}

void Drone::move(PzG::GnuplotLink &link, double angle, double lenght)
{
    Vector3D translation = calculateMove(lenght, angle);
    Vector3D preTranslation = _translation;
    Vector3D oneStepVector = translation / 200;
    bool collision = false;
    
    for(int i = 0; i < 200; i++)
    {
        translate(_translation + oneStepVector);
        _leftRotor.setRotation(_leftRotor.getRotation() - 2);
        _rightRotor.setRotation(_rightRotor.getRotation() + 2);
        draw(kDroneFile);
        this_thread::sleep_for(timespan);
        link.Draw();
        if(checkCollisions())
        {
            collision = true;
            i = 200;
        }
    }
    if(!collision)
    {
        translate(preTranslation + translation);
        draw(kDroneFile);
        link.Draw();
    }
}

void Drone::rotate(PzG::GnuplotLink &link, double angle)
{
    double preAngle = getAngle();
    double oneStepAngle = angle / 200;
    for(int i = 0; i < 200; i++)
    {
        setAngle(_angle + oneStepAngle);
        if(angle > 0)
            _leftRotor.setRotation(_leftRotor.getRotation() - 2);
        else if(angle < 0)
            _rightRotor.setRotation(_rightRotor.getRotation() + 2);
        draw(kDroneFile);
        this_thread::sleep_for(timespan);
        link.Draw();
    }
    setAngle(preAngle + angle);
    draw(kDroneFile);
    link.Draw();
}

Vector3D Drone::calculateMove(double lenght, double angle) const
{
    double Zrad = angle * PI / 180;
    double XYrad = _angle * PI / 180;
    double XYlenght = lenght * cos(Zrad);
    Vector3D translation = _translation;
    translation[2] = lenght * sin(Zrad);
    translation[0] = XYlenght * cos(XYrad);
    translation[1] = XYlenght * sin(XYrad);
    return translation;
}