#pragma once

#include <vector>
#include "Vector.hh"
#include "Matrix.hh"

class Shape
{
protected:
    std::vector<Vector3D> _points;
    Vector3D _translation;
};