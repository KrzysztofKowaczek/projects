#include "SystemOfLinearEquations.hh"
#include <iostream>
#include "Size.hh"
#include <math.h>
#include "Vector.hh"
#include "Matrix.hh"

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy SystemOfLinearEquations, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

std::istream &operator>>(std::istream &stream, SystemOfLinearEquations &system)
{
    Matrix m;
    Vector v;
    stream >> m >> v;
    system.setMatrix(m);
    system.setVector(v);
    return stream; 
}

std::ostream &operator<<(std::ostream &stream,
                         const SystemOfLinearEquations &system)
{
	Vector slip = system.getSlip();
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
		stream << "         Wektor bledu:   Ax-b   = ( " << slip.getCell(0);
		for(int i = 1; i < SIZE; i++)
			stream << ", " << slip.getCell(i);
		stream << " )" << std::endl;
		stream << "Dlugosc wektora bledu: |(Ax-b)| = " << sqrt(slip & slip)
					<< std::endl << std::endl;
	}
	else
		stream << "Nie policzono rownania!" << std::endl << std::endl;
	return stream;
}

Vector SystemOfLinearEquations::calculate()
{
	Vector tmpV;
	Matrix m = this->_m;
	double det[SIZE + 1];
	double tmp;
	det[SIZE] = m.determinant();
	for(int i = 0; i < SIZE; i++)
	{
		m = this->_m;
		m.setVector(i, this->_v);
		det[i] = m.determinant();
	}
	for(int i = 0; i < SIZE; i++)
		this->_result.setCell(i, det[i]/det[SIZE]);
	
	for(int i = 0; i < SIZE; i++)
	{
		tmp = 0;
		for(int j = 0; j < SIZE; j++)
		{
			tmpV = this->_m.getVector(j);
			tmp += tmpV.getCell(i) * this->_result.getCell(j);
		}
		this->_slip.setCell(i, (this->_v.getCell(i) - tmp));
	}

	this->calculated = true;

	return this->_result;
}