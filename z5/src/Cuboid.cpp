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
    Matrix2D matrix;
    calculateAngle(matrix);
    if(!outputFile.is_open())
    {
        cerr << "Unable to open drone file!" << endl;
        return;
    }
    for(unsigned i = 0; i < _points.size(); ++i)
    {
        outputFile << (_points[i] * matrix) + _translation << endl;
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

Vector3D operator*(Vector3D vector, const Matrix2D &matrix)
{
    double tmp0 = vector[0];
    double tmp1 = vector[1];
    vector[0] = (tmp0 * matrix[0][0]) + (tmp1 * matrix[0][1]);
    vector[1] = (tmp0 * matrix[1][0]) + (tmp1 * matrix[1][1]);
    return vector;
}

void Cuboid::calculateAngle(Matrix2D &matrix) const
{
    double radians = _angle * PI / 180.0;
    matrix[0][0] = matrix[1][1] = cos(radians);
    matrix[1][0] = sin(radians);
    matrix[0][1] = -1 * matrix[1][0];
}