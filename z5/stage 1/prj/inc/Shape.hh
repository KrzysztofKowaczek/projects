#pragma once

#include <vector>
#include <string>
#include "Vector.hh"
#include "Matrix.hh"

class Shape
{
protected:
    std::vector<Vector3D> _points;
    Vector3D _translation;
public:
    //void generate(std::string filename) const;
    void translate(const Vector3D &trans) {_translation = trans;}
    Shape(std::string filename);
    Shape() {}
};