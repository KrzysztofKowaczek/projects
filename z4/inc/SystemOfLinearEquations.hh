#pragma once

#include <iostream>
#include <iomanip>
#include "Vector.hh"
#include "Matrix.hh"
#include "Complex.hh"
#include "Size.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template<typename T, int Size>
class SystemOfLinearEquations
{
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  Matrix<T, Size> _m;
  Vector<T, Size> _v;
  Vector<T, Size> _result;
	Vector<T, Size> _slip;
	bool calculated;
public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
  Vector<T, Size> calculate();
  Matrix<T, Size> getMatrix() const {return this->_m;}
  void setMatrix(const Matrix<T, Size> &matrix) {this->_m = matrix;}
  Vector<T, Size> getVector() const {return this->_v;}
  void setVector(const Vector<T, Size> &vector) {this->_v = vector;}
	Vector<T, Size> getResult() const {return this->_result;}
	Vector<T, Size> getSlip() const {return this->_slip;}
	bool isCalculated() const {return calculated;}
};

/*
 * Przeciazenie operatora >> dla wczytania ukladu rownan
 * Uwaga:
 * 					przyjmuje tylko takie dane jak w pliku matrix.dat, czyli np.:
 * 					1.0 2.2 3.1
 * 					4.1 5.2 6.3
 * 					7.7 8.7 9.45
 *          0.2 2.3 3.4
 */
template<typename T, int Size>
std::istream &operator>>(std::istream &stream, SystemOfLinearEquations<T, Size> &system)
{
    Matrix<T, Size> m;
    Vector<T, Size> v;
    stream >> m >> v;
    system.setMatrix(m);
    system.setVector(v);
    return stream; 
}

/*
 * Przeciazenie operatora << dla wypisywania ukladu rownan.
 * Argumenty:
 *           stream - strumien wyjscia,
 *           system - uklad rownan do wypisania.
 * Zwraca:
 *           referencje na strumien wyjsciowy.
 * Uwaga:
 * 					 wypisuje rozne postaci w zaleznosci czy uklad zostal juz 
 * 					 policzony, czy nie.
 */
template<typename T, int Size>
std::ostream &operator<<(std::ostream &stream,
                         const SystemOfLinearEquations<T, Size> &system)
{
	Vector<T, Size> slip = system.getSlip();
	stream << std::fixed << std::setprecision(2);
	stream << "Macierz A^T:" << std::endl << std::endl;
  stream << system.getMatrix() << std::endl;
  stream << "Wektor wyrazow wolnych b:" << std::endl << std::endl;
  stream << system.getVector() << std::endl << std::endl;
	if(system.isCalculated())
	{
		stream << "Rozwiazanie x = (x1";
		for(int i = 0; i < Size - 1; i++)
			stream << ", x" << i + 2;
		stream << "):" << std::endl << std::endl;
		stream << system.getResult() << std::endl << std::endl;
		stream << std::scientific << std::setprecision(1);
		stream << "         Wektor bledu:   Ax-b   = ( " << slip[0];
		for(int i = 1; i < Size; i++)
			stream << ", " << slip[i];
		stream << " )" << std::endl;
	}
	else
		stream << "Nie policzono rownania!" << std::endl << std::endl;
	return stream;
}

/*
 * Metoda klasy SystemOfLinearEquations, oblicza uklad rownan.
 * Zwraca:
 * 					wektor bedacy rozwiazaniem ukladu rownan.
 */
template<typename T, int Size>
Vector<T, Size> SystemOfLinearEquations<T, Size>::calculate()
{
	Vector<T, Size> tmpV;
	Matrix<T, Size> m = this->_m;
	T det[Size + 1];
	T tmp;
	det[Size] = m.determinant();
	for(int i = 0; i < Size; i++)
	{
		m = this->_m;
		m[i] = this->_v;
		det[i] = m.determinant();
	}
	for(int i = 0; i < Size; i++)
		this->_result[i] = det[i]/det[Size];
	
	for(int i = 0; i < Size; i++)
	{
		tmp = 0;
		for(int j = 0; j < Size; j++)
		{
			tmpV = this->_m[j];
			tmp = tmp + tmpV[i] * this->_result[j];
		}
		this->_slip[i] = (this->_v[i] - tmp);
	}

	this->calculated = true;

	return this->_result;
}
