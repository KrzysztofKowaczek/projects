#include "Matrix.hh"
#include "Vector.hh"
#include "Size.hh"
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
 *          1 jesli podano dobry ind, 0 w przeciwnym przypadku.
 */
int Matrix::setVector(unsigned int ind, const Vector &vector)
{
  if(ind < SIZE)
    this->_m[ind] = vector;
  else
    return 0;
  return 1;
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

std::istream &operator>>(std::istream &stream, Matrix &matrix)
{
  double val;
  Vector vect;
  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE; j++)
    {
      stream >> val;
      vect.setCell(j, val);
    }
    matrix.setVector(i, vect);
  }
  return stream;
}