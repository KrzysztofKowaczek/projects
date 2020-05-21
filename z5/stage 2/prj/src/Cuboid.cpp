#include "Cuboid.hh"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

constexpr double PI = 3.14159265;

void Cuboid::draw(std::string filename) const
{
    ofstream outputFile;
    outputFile.open(filename);
    Matrix3D matrix;
    matrix.rotationZ(_angle);
    if(!outputFile.is_open())
    {
        cerr << "Unable to open cuboid file!" << endl;
        return;
    }
    for(unsigned i = 0; i < _points.size(); ++i)
    {
        outputFile << (matrix * _points[i]) + _translation << endl;
        if(i % 4 == 3) // triggers after every 4 points
        {
            outputFile << "#\n\n";
        }
    }
}

Cuboid::Cuboid(): _angle{0}
{
    ifstream inputFile;
    inputFile.open(kModelCuboid);
    if(!inputFile.is_open())
    {
        cerr << "Unable to load model Cuboid file!" 
             << endl;
        return;
    }

    Vector3D point;
    while(inputFile >> point)
    {
        _points.push_back(point);
    }
    inputFile.close();
}