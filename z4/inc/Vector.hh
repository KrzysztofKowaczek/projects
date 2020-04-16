#pragma once

#include "Size.hh"
#include <iostream>

/*
 * Klasa Vector modeluje pojecie wektora wielowymiarowego.
 * Pola:
 *      _v - tablica liczb rzeczywistych stanowiacych wektor.
 */
// do kopiowania: <T, SIZE> <double, SIZE>
template <typename T, int SIZE>
class Vector
{

  T _v[SIZE];
public:
  void operator += (const Vector &vec);
  void operator -= (const Vector &vec);
  void operator *= (const double val);
  void operator /= (const double val);
  Vector operator + (const Vector &vec2) const;
  Vector operator - (const Vector &vec2) const;
  double operator & (const Vector &vec2) const;
  Vector operator * (double val) const;
  Vector operator / (double val) const;
  double getCell(unsigned int row) const;
  int setCell(unsigned int row, const double &value);
  Vector();
};

std::istream &operator>>(std::istream &stream, Vector<double, SIZE> &vec);
std::ostream &operator<<(std::ostream &stream, const Vector<double, SIZE> &vec);