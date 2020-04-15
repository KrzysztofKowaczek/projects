#include <iostream>
#include "Vector.hh"
#include "Matrix.hh"
#include "SystemOfLinearEquations.hh"

using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */

int main()
{
  SystemOfLinearEquations system; // To tylko przykladowe definicje zmiennej
  Matrix m;
  Vector v;

  cout << endl
       << " Start programu " << endl
       << endl;
  
  cin >> m;
  cin >> v;

  cout << "Macierz A^T:" << endl << endl;
  cout << m << endl;
  cout << "Wektor wyrazow wolnych b:" << endl << endl;
  cout << v << endl << endl;
  m.determinant();
}
