#include <iostream>
#include "Complex.hh"
#include "Vector.hh"
#include "Matrix.hh"
#include "SystemOfLinearEquations.hh"

using namespace std;

int main()
{
  
  SystemOfLinearEquations<Complex, 5> system;

  cout << endl
       << " Start programu " << endl
       << endl;
  
  cin >> system;
  system.calculate();
  cout << system;
  
  return 0;
}
