#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <memory>

#include "gnuplot_link.hh"
#include "Drone.hh"
#include "Cuboid.hh"
#include "Vector.hh"
#include "Matrix.hh"
#include "Objects.hh"
#include "filenames.hh"

using namespace std;

const string kMenuEndProg("k");
const string kMenuOrientation("o");
const string kMenuRush("r");
const string kMenuMenuShow("m"); 

void showMenu();
Vector3D calculateMove(double lenght, double angle, const Drone &drone);

int main()
{
    string userOption;

    Drone drone;
    PzG::GnuplotLink link; // Ta zmienna jest potrzebna do wizualizacji
    drone.draw(kDroneFile);

    link.Init();
    link.AddFilename(kDroneFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kFloorFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kCeilFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kPlateFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kStickFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kCuboidFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.SetDrawingMode(PzG::DM_3D);
    link.Draw();

    showMenu();

    do
    {
        cout << "Twoj wybor, m - menu> ";
        cin >> userOption;
        cout << endl;
        if(userOption == kMenuMenuShow)
            showMenu();
        else if(userOption == kMenuOrientation)
        {
            double angle;
            cout << " Podaj wartosc kata obrotu w stopniach." << endl;
            cout << " Wartosc kata> ";
            cin >> angle;
            drone.rotate(link, angle);
        }
        else if(userOption == kMenuRush)
        {
            Vector3D translation;
            double angle = 0;
            double lenght = 0;
            cout << " Podaj wartosc kata (wznoszenia/opadania) w stopniach."
                 << endl;
            cout << " Wartosc kata> ";
            cin >> angle;
            cout << endl << " Podaj wartosc odleglosci, na ktora ma sie"
                 << " przeniesc dron" << endl;
            cout << " Wartosc odleglosci> ";
            cin >> lenght;
            cout << endl;
            drone.move(link, angle, lenght);
        }
        else if(userOption != kMenuEndProg)
            cout << "Zla opcja menu!" << endl << endl;
    } while (userOption != kMenuEndProg);
    return 0;
}

void showMenu()
{
    cout << endl << " r - zadaj ruch na wprost" << endl;
    cout << " o - zadaj zmiane orientacji" << endl;
    cout << " m - wyswietl menu" << endl << endl;
    cout << " k - koniec dzialania programu" << endl << endl;
}