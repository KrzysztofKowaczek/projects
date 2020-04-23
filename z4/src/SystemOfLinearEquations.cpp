#include "SystemOfLinearEquations.hh"
#include <iostream>
#include "Size.hh"
#include <math.h>
#include "Vector.hh"
#include "Matrix.hh"

/*
 * Przeciazenie operatora >> dla wczytania ukladu rownan
 * Uwaga:
 * 					przyjmuje tylko takie dane jak w pliku matrix.dat, czyli np.:
 * 					1.0 2.2 3.1
 * 					4.1 5.2 6.3
 * 					7.7 8.7 9.45
 *          0.2 2.3 3.4
 */
std::istream &operator>>(std::istream &stream, SystemOfLinearEquations &system)
{
    Matrix<double, SIZE> m;
    Vector<double, SIZE> v;
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
std::ostream &operator<<(std::ostream &stream,
                         const SystemOfLinearEquations &system)
{
	Vector<double, SIZE> slip = system.getSlip();
	stream << "Macierz A^T:" << std::endl << std::endl;
  stream << system.getMatrix() << std::endl;
  stream << "Wektor wyrazow wolnych b:" << std::endl << std::endl;
  stream << system.getVector() << std::endl << std::endl;
	if(system.isCalculated())
	{
		stream << "Rozwiazanie x = (x1";
		for(int i = 0; i < SIZE - 1; i++)
			stream << ", x" << i + 2;
		stream << "):" << std::endl << std::endl;
		stream << system.getResult() << std::endl << std::endl;
		stream << "         Wektor bledu:   Ax-b   = ( " << slip[0];
		for(int i = 1; i < SIZE; i++)
			stream << ", " << slip[i];
		stream << " )" << std::endl;
		stream << "Dlugosc wektora bledu: |(Ax-b)| = " << sqrt(slip & slip)
					<< std::endl << std::endl;
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
Vector<double, SIZE> SystemOfLinearEquations::calculate()
{
	Vector<double, SIZE> tmpV;
	Matrix<double, SIZE> m = this->_m;
	double det[SIZE + 1];
	double tmp;
	det[SIZE] = m.determinant();
	for(int i = 0; i < SIZE; i++)
	{
		m = this->_m;
		m[i] = this->_v;
		det[i] = m.determinant();
	}
	for(int i = 0; i < SIZE; i++)
		this->_result[i] = det[i]/det[SIZE];
	
	for(int i = 0; i < SIZE; i++)
	{
		tmp = 0;
		for(int j = 0; j < SIZE; j++)
		{
			tmpV = this->_m[j];
			tmp += tmpV[i] * this->_result[j];
		}
		this->_slip[i] = (this->_v[i] - tmp);
	}

	this->calculated = true;

	return this->_result;
}