#pragma once

#include <iostream>
#include "Vector.hh"
#include "Matrix.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class SystemOfLinearEquations
{
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  Matrix _m;
  Vector<double, SIZE> _v;
  Vector<double, SIZE> _result;
	Vector<double, SIZE> _slip;
	bool calculated;
public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
  Vector<double, SIZE> calculate();
  Matrix getMatrix() const {return this->_m;}
  void setMatrix(const Matrix &matrix) {this->_m = matrix;}
  Vector<double, SIZE> getVector() const {return this->_v;}
  void setVector(const Vector<double, SIZE> &vector) {this->_v = vector;}
	Vector<double, SIZE> getResult() const {return this->_result;}
	Vector<double, SIZE> getSlip() const {return this->_slip;}
	bool isCalculated() const {return calculated;}
};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream &operator>>(std::istream &stream, SystemOfLinearEquations &system);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream &operator<<(std::ostream &stream,
                         const SystemOfLinearEquations &system);
