#include <iostream>
#include <fstream>
#include <cstring>
#include "Complex.hh"
#include "Vector.hh"
#include "Matrix.hh"
#include "SystemOfLinearEquations.hh"

using namespace std;

int main(int argc, char *argv[])
{
  ifstream inFile;
  SystemOfLinearEquations<Complex, 5> complexSystem;
  SystemOfLinearEquations<double, 5> doubleSystem;
  if(argc < 2)
  {
    cout << "Nie podano argumentow wywolania programu!" << endl;
    cout << "Poprawne wywolanie programu brzmi: " << endl << argv[0] << " r|z" << endl;
  }
  else
  {
    if(!strcmp(argv[1], "r"))
    {
      inFile.open("double.dat");
      if(inFile.is_open())
      {
        inFile >> doubleSystem;
        doubleSystem.calculate();
        cout << doubleSystem;
      }
      else
        cout << "Blad otwarcia pliku!" << endl;
    }
    else if(!strcmp(argv[1], "z"))
    {
      inFile.open("complex.dat");
      if(inFile.is_open())
      {
        inFile >> complexSystem;
        complexSystem.calculate();
        cout << complexSystem;
      }
      else
        cout << "Blad otwarcia pliku!" << endl;
    }
  }
  if(inFile.is_open())
    inFile.close();
  return 0;
}
