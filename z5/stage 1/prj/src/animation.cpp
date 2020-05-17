#include "gnuplot_link.hh"
#include "Vector.hh"
#include "Cuboid.hh"
#include "filenames.hh"

#include <chrono>
#include <thread>

using namespace std;

chrono::duration<int, milli> timespan(20); 

void animate(PzG::GnuplotLink &link, Cuboid &cuboid, 
            const Vector3D &translation, double angle)
{
    Vector3D preTranslation = cuboid.getTranslation();
    double preAngle = cuboid.getAngle();
    Vector3D oneStepVector = translation / 200;
    double oneStepAngle = angle / 200;

    for(int i = 0; i < 200; i++)
    {
        this_thread::sleep_for(timespan);
        cuboid.translate(cuboid.getTranslation() + oneStepVector);
        cuboid.setAngle(cuboid.getAngle() + oneStepAngle);
        cuboid.draw(kDroneFile);
        link.Draw();
    }
    cuboid.translate(preTranslation + translation);
    cuboid.setAngle(preAngle + angle);
    cuboid.draw(kDroneFile);
    link.Draw();
}