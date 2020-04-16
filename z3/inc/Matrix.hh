#pragma once

#include "Size.hh"
#include "Vector.hh"
#include <iostream>

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Matrix
{
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  Vector _m[SIZE];
  static bool checkIfZeroDiagonal(Vector *m, int &place);
  void replaceRows(Vector *m, int row1, int row2) const;
  static void eliminationMethodGauss(Vector *m);
public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
  Vector getVector(unsigned int ind) const;
  bool setVector(unsigned int ind, const Vector &vector);
  double determinant() const;
  Matrix();
};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream &operator>>(std::istream &stream, Matrix &matrix);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream &operator<<(std::ostream &stream, const Matrix &matrix);
