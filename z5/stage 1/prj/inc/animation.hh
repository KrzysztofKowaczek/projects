#pragma once

#include "gnuplot_link.hh"
#include "Vector.hh"
#include "Cuboid.hh"

void animate(PzG::GnuplotLink &link, Cuboid &cuboid, 
            const Vector3D &translation, double angle);