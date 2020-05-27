#include "Scene.hh"
#include "Cuboid.hh"
#include "Objects.hh"
#include "filenames.hh"

#include <memory>

using namespace std;
using namespace Objects;

Scene::Scene()
{
    objects.push_back(make_shared<Cuboid>(kCuboidFile));
    objects.push_back(make_shared<Plate>(kPlateFile));
    objects.push_back(make_shared<Stick>(kStickFile));
    objects.push_back(make_shared<Ceil>(kCeilFile));
    objects.push_back(make_shared<Floor>(kFloorFile));
}