#include <iostream>
#include "Vector.hh"
#include "Matrix.hh"
#include "SystemOfLinearEquations.hh"

using namespace std;

int main()
{
  SystemOfLinearEquations system; // To tylko przykladowe definicje zmiennej

  cout << endl
       << " Start programu " << endl
       << endl;
  
  cin >> system;
  system.calculate();
  cout << system;
  return 0;
}
