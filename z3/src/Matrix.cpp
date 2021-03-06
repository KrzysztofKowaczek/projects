#include "Matrix.hh"
#include "Vector.hh"
#include "Size.hh"
#include "math.h"
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Matrix, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

/*
 * Metoda interfejsu klasy Matrix, daje mozliwosc odczytu komorki macierzy.
 * Argumety:
 *          row - wiersz macierzy (0 odnosi sie do 1 wierszu),
 *          col - kolumna macierzy (0 odnosi sie do 1 kolumny).
 * Warunki wstepne:
 *          ind nie moga byc wieksze niz stopien macierzy - 1.
 * Zwraca:
 *          Wartosc komorki macierzy.
 */
Vector Matrix::getVector(unsigned int ind) const
{
  if(ind < SIZE)
    return this->_m[ind];
  
  Vector v;
  return v;
}

/*
 * Metoda interfejsu Matrix, daje mozliwosc zapisu do wektora macierzy
 * Argumety:
 *          ind - indeks wektora macierzy (0 odnosi sie do 1 wektora),
 *          value - wartosc do przypisania do komorki
 * Warunki wstepne:
 *          ind nie moze byc wieksze niz stopien macierzy - 1.
 * Zwraca:
 *          true jesli podano dobry ind, false w przeciwnym przypadku.
 */
bool Matrix::setVector(unsigned int ind, const Vector &vector)
{
  if(ind < SIZE)
    this->_m[ind] = vector;
  else
    return false;
  return true;
}

/*
 * Metoda klasy Matrix, oblicza wyznacznik macierzy.
 * Zwraca:
 *           wyznacznik macierzy 
 */
double Matrix::determinant() const
{
  Vector m[SIZE]; // Kopia macierzy, na niej wykonywane są wszystkie operacje
  int rowChanges = 0, place;
  double det = 1;
  for(int i = 0; i < SIZE; i++)
    for(int j = 0; j < SIZE; j++)
      m[i].setCell(j, this->_m[j].getCell(i)); // Transponowanie macierzy
  
  while(checkIfZeroDiagonal(m, place))
  {
    int bitmap = 0;
    for(int i = 0; i < SIZE; i++)
      // Oznacz niezerowe komorki w kolumnie
      if(abs(m[i].getCell(place)) > 0.0000001)
        bitmap |= (1 << i); 

    if(bitmap == 0) // Jesli kolumna zawiera same zera 
      return 0;

    for(int i = 0; i < SIZE; i++)
      if(bitmap & (1 << i)) // Sprawdz ktory jest pierwszy niezerowy
      {
        replaceRows(m, place, i); // Zamien wiersz niezerowy z zerowym
        i = SIZE; // Zatrzymuje petle
      }
    rowChanges++;
  }
  eliminationMethodGauss(m);
  for(int i = 0; i < SIZE; i++) 
    det *= m[i].getCell(i);
  // Uwzglednienie liczby przestawien wierszy
  if(rowChanges % 2) det *= -1;
  return det;
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
bool Matrix::checkIfZeroDiagonal(Vector *m, int &place)
{
  bool result = false;
  for(int i = 0; i < SIZE; i++)
    if(abs(m[i].getCell(i)) < 0.0000001)
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
void Matrix::replaceRows(Vector *m, int row1, int row2) const
{
  Vector tmpV;
  tmpV = m[row1];
  m[row1] = m[row2];
  m[row2] = tmpV;
}

/*
 * Metoda statyczna klasy Matrix, sprowadza macierz do postaci trojkatnej.
 * Argumenty:
 *            m - wskaznik na tablice wektorow tworzacych macierz.
 */
void Matrix::eliminationMethodGauss(Vector *m)
{
  int row, col;
  double quotient;
  for(col = 0; col < SIZE; col++)
    for(row = SIZE - 1; row > col; row--)
    {
      if(abs(m[row].getCell(col)) > 0.0000001)
      {
        quotient = m[row].getCell(col) / m[col].getCell(col);
        m[row] -= m[col] * quotient;
      }
    }
}

/*
 * Konstruktor macierzy, inicjalizuje ja zerami.
 */
Matrix::Matrix()
{
  Vector v;
  for(int i = 0; i < SIZE; i++)
    this->_m[i] = v;
}

/*
 * Przeciazenie operatora << dla wypisywania macierzy.
 * Argumenty:
 *           stream - strumien wyjscia,
 *           matrix - macierz do wypisania.
 * Zwraca:
 *           referencje na strumien wyjsciowy.
 */
std::ostream &operator<<(std::ostream &stream, const Matrix &matrix)
{
  for(int i = 0; i < SIZE; i++)
    stream << matrix.getVector(i) << std::endl;

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
std::istream &operator>>(std::istream &stream, Matrix &matrix)
{
  Vector vect;
  for(int i = 0; i < SIZE; i++)
  {
    stream >> vect;
    matrix.setVector(i, vect);
  }
  return stream;
}