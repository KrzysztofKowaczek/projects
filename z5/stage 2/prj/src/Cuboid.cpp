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
    outputFile.close();
}

void Cuboid::setAngle(double angle) 
{
    _angle = angle;
    while(_angle > 360) 
        _angle -= 360;
    while(_angle < 0)
        _angle += 360;
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
    std::string line;
    while(inputFile >> point)
        _points.push_back(point);

    inputFile.close();
}

Cuboid::Cuboid(std::string filename): _angle{0}
{
    ifstream inputFile;
    inputFile.open(filename);
    if(!inputFile.is_open())
    {
        cerr << "Unable to load cuboid file!" 
             << endl;
        return;
    }

    Vector3D point;
    std::string str;
    while(!inputFile.fail())
    {
        inputFile >> str;
        if(str[0] != '#')  
            for(signed i = str.length(); i > 0; --i)
                inputFile.putback(str[i - 1]);
        
        if(inputFile >> point)
            _points.push_back(point);
            
    }
    inputFile.close();
}