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
  Vector<int, 2> v;
  Matrix<Complex, 2> m;
  cin << m;
  cout >> m;

  return 0;
}
