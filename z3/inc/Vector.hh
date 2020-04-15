#pragma once

#include "Size.hh"
#include <iostream>

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Vector
{
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  double _v[SIZE];
public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
  void operator += (const Vector &vec);
  void operator -= (const Vector &vec);
  void operator *= (double val);
  void operator /= (double val);
  double getCell(unsigned int row) const;
  int setCell(unsigned int row, const double &value);
  Vector();
};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream &operator>>(std::istream &stream, Vector &vec);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream &operator<<(std::ostream &stream, const Vector &vec);

Vector operator + (const Vector &vec1, const Vector &vec2);
Vector operator - (const Vector &vec1, const Vector &vec2);
double operator & (const Vector &vec1, const Vector &vec2);
Vector operator * (const Vector &vec, double val);
Vector operator / (const Vector &vec, double val);