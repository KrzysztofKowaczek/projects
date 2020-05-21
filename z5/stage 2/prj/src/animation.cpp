#include "gnuplot_link.hh"
#include "Vector.hh"
#include "Cuboid.hh"
#include "Drone.hh"
#include "filenames.hh"

#include <chrono>
#include <thread>

using namespace std;

chrono::duration<int, milli> timespan(20); 

void animate(PzG::GnuplotLink &link, Drone &drone, 
            const Vector3D &translation, double angle)
{
    Vector3D preTranslation = drone.getTranslation();
    double preAngle = drone.getAngle();
    while(angle > 360) angle -= 360;
    Vector3D oneStepVector = translation / 500;
    double oneStepAngle = angle / 500;

    for(int i = 0; i < 500; i++)
    {
        this_thread::sleep_for(timespan);
        drone.translate(drone.getTranslation() + oneStepVector);
        drone.setAngle(drone.getAngle() + oneStepAngle);
        drone.draw(kDroneFile);
        link.Draw();
    }
    drone.translate(preTranslation + translation);
    drone.setAngle(preAngle + angle);
    drone.draw(kDroneFile);
    link.Draw();
}