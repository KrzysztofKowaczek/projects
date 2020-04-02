#pragma once

#include "Size.hh"
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
  double _m[SIZE][SIZE];
public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
  double getCell(unsigned int row, unsigned int col) const;
  int writeCell(unsigned int row, unsigned int col, const double &value);
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
std::istream &operator>>(std::istream &stream, const Matrix &matrix);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream &operator<<(std::ostream &stream, const Matrix &matrix);
