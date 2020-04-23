#include <iostream>
#include "Complex.hh"
#include "Vector.hh"
#include "Matrix.hh"
#include "SystemOfLinearEquations.hh"

using namespace std;

int main()
{/*
  SystemOfLinearEquations system; // To tylko przykladowe definicje zmiennej

  cout << endl
       << " Start programu " << endl
       << endl;
  
  cin >> system;
  system.calculate();
  cout << system;*/

  Matrix<Complex, SIZE> m;
  cin >> m;
  cout << m.determinant() << endl;
  cout << "Chyba cos poszlo nie tak... Naprawie to w najblizszym czasie :)" << endl << endl;
  
  return 0;
}
