#include <fstream>
#include <iostream>

#include "Rotor.hh"
#include "Vector.hh"
#include "filenames.hh"

using namespace std;

void Rotor::draw(std::string filename) const
{
    Vector3D location;
    Matrix3D matrixY, matrixZ;
    ofstream outputFile;
    unsigned i;
    outputFile.open(filename, ios_base::app);
    matrixZ.rotationZ(_angle);
    matrixY.rotationY(_rotation);
    location = matrixZ * _mountPoint + _translation;  
    if(!outputFile.is_open())
    {
        cerr << "Unable to open Rotor outputfile!" << endl;
        return;
    }

    outputFile << endl << endl;
    for(i = 0; i < 7; ++i)
        outputFile << matrixZ * (matrixY * _points[i]) + location << endl;

    outputFile << "#\n\n";
    for(; i < 14; ++i)
        outputFile << matrixZ * (matrixY * _points[i]) + location << endl;

    outputFile << "#\n\n\n"; 
    for(; i < 19;  ++i)
        outputFile << matrixZ * (matrixY * _points[i]) + location << endl;

    outputFile << "#\n\n\n";
    for(; i < 23; ++i)
        outputFile << matrixZ * (matrixY * _points[i]) + location << endl;

    outputFile << "#\n\n\n";
    for(; i < 27; ++i)
        outputFile << matrixZ * (matrixY * _points[i]) + location << endl;

    outputFile << "#\n";
    outputFile.close();
}

Rotor::Rotor(): _angle(0), _rotation(0)
{
    ifstream inputFile;
    inputFile.open(kModelRotor);
    if(!inputFile.is_open())
    {
        cout << "Unable to open Rotor file!" << endl;
        return;
    }

    Vector3D point;
    while(inputFile >> point)
    {
        _points.push_back(point);
    }
    inputFile.close();
}

void Rotor::setAngle(double angle) 
{
    _angle = angle; 
    while(_angle > 360) 
        _angle -= 360;
    while(_angle < 0)
        _angle += 360;
}

void Rotor::setRotation(double rotation)
{
    _rotation = rotation; 
    while(_rotation > 360) 
        _rotation -= 360;
    while(_rotation < 0)
        _rotation += 360;
}