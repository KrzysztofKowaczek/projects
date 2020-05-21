#pragma once

#include "Vector.hh"
#include <iostream>
#include <cmath>

constexpr double ERR_MARGIN = 0.0000001;

/*
 * Klasa Matrix modeluje pojecie macierzy wielowymiarowej.
 * Pola:
 *      _m - tablica wektorow stanowiacych macierz.
 */
template<typename T, int Size>
class Matrix
{
protected:
  Vector<T, Size> _m[Size];
  Vector<T, Size> badVect;
  bool checkIfZeroDiagonal(Vector<T, Size> *m, int &place) const;
  void replaceRows(Vector<T, Size> *m, int row1, int row2) const;
  void eliminationMethodGauss(Vector<T, Size> *m) const;
public:
  //Matrix() {for(Vector<T, Size> &vect: _m) vect = 0;}
  T determinant() const;
  Vector<T, Size> operator[](unsigned int idx) const
		{if(idx < Size) return _m[idx]; return badVect;}
	Vector<T, Size> &operator[](unsigned int idx)
		{if(idx < Size) return _m[idx]; return badVect;}
  static double abs(double val) {return sqrt(val*val);}
  Vector<T, Size> operator*(const Vector<T, Size> &vect) const;
};

class Matrix3D: public Matrix<double, 3>
{
public:
  void rotationX(double angle);
  void rotationY(double angle);
  void rotationZ(double angle);
};

/*
 * Przeciazenie operatora << dla wypisywania macierzy.
 * Argumenty:
 *           stream - strumien wyjscia,
 *           matrix - macierz do wypisania.
 * Zwraca:
 *           referencje na strumien wyjsciowy.
 */
template<typename T, int Size>
std::ostream &operator<<(std::ostream &stream, const Matrix<T, Size> &matrix)
{
  for(int i = 0; i < Size; i++)
    stream << matrix[i] << std::endl;

  return stream;
}

/*
 * Przeciazenie operatora >> dla wczytywania macierzy.
 * Argumenty:
 *           stream - strumien wejscia,
 *           matrix - macierz do wczytania.
 * Zwraca:
 *           referencje na strumien wejsciowy.
 * Uwaga:
 *           liczby powinny być postaci np.:
 *           1 2 3
 *           4 5 6
 *           7 8 9
 */
template<typename T, int Size>
std::istream &operator>>(std::istream &stream, Matrix<T, Size> &matrix)
{
  Vector<T, Size> vect;
  for(int i = 0; i < Size; i++)
  {
    stream >> vect;
    matrix[i] = vect;
  }
  return stream;
}

/* 
 * Metoda statyczna klasy Matrix, sprawdza czy macierz posiada zera po ukosie.
 * Modyfikuje argument place.
 * Argumenty:
 *            m - wskażnik na tablice wektorów tworzących macierz,
 *            place - argument modyfikowany, po wywołaniu przechowuje 
 *                    indeks kolumny=wiersza, gdzie jest zero
 * Zwraca:
 *            true, jesli wystepuja zera w macierzy, false jesli nie
 */
template<typename T, int Size>
bool Matrix<T, Size>::checkIfZeroDiagonal(Vector<T, Size> *m, int &place) const
{
  bool result = false;
  for(int i = 0; i < Size; i++)
    if(abs(m[i][i]) < ERR_MARGIN)
    {
      result = true;
      place = i;
    }
  return result;
}

/*
 * Metoda klasy Matrix, zamienia wiersze w macierzy.
 * Argumenty:
 *            m - wskażnik na tablice wektorów tworzących macierz,
 *            row1 - pierwszy indeks wierszu do zamiany,
 *            row2 - drugi indeks wierszu do zamiany.
 */
template<typename T, int Size>
void Matrix<T, Size>::replaceRows(Vector<T, Size> *m, int row1, int row2) const
{
  Vector<T, Size> tmpV;
  tmpV = m[row1];
  m[row1] = m[row2];
  m[row2] = tmpV;
}

/*
 * Metoda statyczna klasy Matrix, sprowadza macierz do postaci trojkatnej.
 * Argumenty:
 *            m - wskaznik na tablice wektorow tworzacych macierz.
 */
template<typename T, int Size>
void Matrix<T, Size>::eliminationMethodGauss(Vector<T, Size> *m) const
{
  int row, col;
  T quotient;

  for(col = 0; col < Size; col++)
    for(row = Size - 1; row > col; row--)
    {
      if(abs(m[row][col]) > ERR_MARGIN)
      {
        quotient = m[row][col] / m[col][col];
        m[row] -= m[col] * quotient;
      }
    }
}

/*
 * Metoda klasy Matrix, oblicza wyznacznik macierzy.
 * Zwraca:
 *           wyznacznik macierzy 
 */
template<typename T, int Size>
T Matrix<T, Size>::determinant() const
{
  Vector<T, Size> m[Size]; // Kopia macierzy, na niej wykonywane są wszystkie operacje
  int rowChanges = 0, place;
  T det;
  det = 1;
  for(int i = 0; i < Size; i++)
    for(int j = 0; j < Size; j++)
      m[i][j] = this->_m[j][i]; // Transponowanie macierzy

  while(checkIfZeroDiagonal(m, place))
  {
    int bitmap = 0;
    for(int i = 0; i < Size; i++)
      // Oznacz niezerowe komorki w kolumnie
      if(abs(m[i][place]) > ERR_MARGIN)
        bitmap |= (1 << i); 

    for(int i = 0; i < Size; i++)
      if(bitmap & (1 << i)) // Sprawdz ktory jest pierwszy niezerowy
      {
        replaceRows(m, place, i); // Zamien wiersz niezerowy z zerowym
        i = Size; // Zatrzymuje petle
      }
    rowChanges++;
  }
  eliminationMethodGauss(m);
  for(int i = 0; i < Size; i++) 
    det *= m[i][i];
  // Uwzglednienie liczby przestawien wierszy
  if(rowChanges % 2) det *= -1;
  return det;
}

/* Metoda klasy szablonowej Matrix, 
 * mnozy macierz przez wektor o tych samych rozmiarach.
 * Argumenty:
 *      vect - wektor, przez ktory mnozymy macierz.
 * Zwraca:
 *      wektor wynikowy mnozenia.
 */
template<typename T, int Size>
Vector<T, Size> Matrix<T, Size>::operator*(const Vector<T, Size> &vect) const
{
  Vector<T, Size> result;
  for(int i = 0; i < Size; i++)
    for(int j = 0; j < Size; j++)
      result[i] += this->_m[i][j] * vect[j];

  return result;
}