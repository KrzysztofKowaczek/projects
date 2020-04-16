#pragma once

#include "Size.hh"
#include "Vector.hh"
#include <iostream>

/*
 * Klasa Matrix modeluje pojecie macierzy wielowymiarowej.
 * Pola:
 *      _m - tablica wektorow stanowiacych macierz.
 */
class Matrix
{
  Vector _m[SIZE];
  static bool checkIfZeroDiagonal(Vector *m, int &place);
  void replaceRows(Vector *m, int row1, int row2) const;
  static void eliminationMethodGauss(Vector *m);
public:
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
