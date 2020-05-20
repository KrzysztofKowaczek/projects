#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

#include "gnuplot_link.hh"
#include "Cuboid.hh"
#include "Vector.hh"
#include "Matrix.hh"
#include "animation.hh"
#include "filenames.hh"

using namespace std;

constexpr double PI = 3.14159265;

const string kMenuEndProg("k");
const string kMenuOrientation("o");
const string kMenuRush("r");
const string kMenuMenuShow("m"); 

void showMenu();
Vector3D calculateMove(double lenght, double angle, const Cuboid &cuboid);

int main()
{
    string userOption;
    Cuboid cuboid;        // To tylko przykladowe definicje zmiennej
    PzG::GnuplotLink link; // Ta zmienna jest potrzebna do wizualizacji
    cuboid.draw(kDroneFile);

    link.Init();
    link.AddFilename(kDroneFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kSurfaceFile.c_str(), PzG::LS_CONTINUOUS, 1);
    link.AddFilename(kCeilFile.c_str(), PzG::LS_CONTINUOUS, 1);
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
            animate(link, cuboid, 0, angle);
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
            translation = calculateMove(lenght, angle, cuboid);
            animate(link, cuboid, translation, 0);
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

Vector3D calculateMove(double lenght, double angle, const Cuboid &cuboid)
{
    double Zrad = angle * PI / 180;
    double XYrad = cuboid.getAngle() * PI / 180;
    double XYlenght = lenght * cos(Zrad);
    Vector3D translation = cuboid.getTranslation();
    translation[2] = lenght * sin(Zrad);
    translation[0] = XYlenght * cos(XYrad);
    translation[1] = XYlenght * sin(XYrad);
    return translation;
}