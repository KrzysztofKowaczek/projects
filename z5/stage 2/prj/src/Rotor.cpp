#include <fstream>
#include <iostream>

#include "Rotor.hh"
#include "Vector.hh"
#include "filenames.hh"

using namespace std;

void Rotor::draw(std::string filename) const
{
    Vector3D location;
    Matrix3D matrixX, matrixZ;
    ofstream outputFile;
    unsigned i;
    outputFile.open(filename, ios_base::app);
    matrixZ.rotationZ(_angle);
    matrixX.rotationX(_rotation);
    location = matrixZ * _mountPoint + _translation;  
    if(!outputFile.is_open())
    {
        cerr << "Unable to open Rotor outputfile!" << endl;
        return;
    }

    outputFile << endl << endl;
    for(i = 0; i < 7; ++i)
        outputFile << matrixZ * (matrixX * _points[i]) + location << endl;

    outputFile << "#\n\n";
    for(; i < 14; ++i)
        outputFile << matrixZ * (matrixX * _points[i]) + location << endl;

    outputFile << "#\n\n\n"; 
    for(; i < 19;  ++i)
        outputFile << matrixZ * (matrixX * _points[i]) + location << endl;

    outputFile << "#\n\n\n";
    for(; i < 23; ++i)
        outputFile << matrixZ * (matrixX * _points[i]) + location << endl;

    outputFile << "#\n\n\n";
    for(; i < 27; ++i)
        outputFile << matrixZ * (matrixX * _points[i]) + location << endl;

    outputFile << "#\n";
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