#include "Shape.hh"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Shape::Shape(std::string filename)
{
    std::ifstream inputFile;
    inputFile.open(filename);
    if(!inputFile.is_open())
    {
        cerr << "Unable to load " << filename << " file!" 
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
/*
void Shape::generate(std::string filename) const
{
    ofstream outputFile;
    outputFile.open(filename);
    Vector3D translation(200);

    for(unsigned i = 0; i < 10; i++)
    {
        translation[0] = 40 * i;
        for(unsigned j = 0; j < 10; j++)
        {
            translation[1] = 40 * j;
            for(unsigned k = 0; k < _points.size(); ++k)
            {
                File << _points[k] + translation << endl;
            }
        }
        outputFile << "\n";
    }
}*/