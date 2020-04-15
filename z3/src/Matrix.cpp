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

double Matrix::determinant() const
{
  Vector m[SIZE]; // Kopia macierzy, na niej wykonywane są wszystkie operacje
  int row, col, rowChanges = 0, place;
  for(int i = 0; i < SIZE; i++)
    m[i] = this->_m[i];
  
  while(checkIfZeroDiagonal(m, place))
  {
    int bitmap = 0, rowChanged = 0;
    for(int i = 0; i < SIZE; i++)
    {
      // Oznacz niezerowe komorki w kolumnie
      if(this->_m[place].getCell(i) != 0)
        bitmap |= (1 << i); 
    }
    if(bitmap == 0) // Jesli kolumna zawiera same zera 
      return 0;

    for(int i = 0; i < SIZE; i++)
      if(bitmap & (1 << i) && !rowChanged) // Sprawdz ktory jest pierwszy niezerowy
      {
        replaceRows(m, place, i); // Zamien wiersz niezerowy z zerowym
        rowChanged = 1;
      }
    rowChanges++;
    std::cout << m[0] << m[1] << m[2] << std::endl;
  }
}

bool Matrix::checkIfZeroDiagonal(Vector *m, int &place) const
{
  bool result = false;
  for(int i = 0; i < SIZE; i++)
    if(m[i].getCell(i) == 0)
    {
      result = true;
      place = i;
    }
  return result;
}

void Matrix::replaceRows(Vector *m, int row1, int row2) const
{
  for(int i = 0; i < SIZE; i++)
  {
    m[i].setCell(row1, this->_m[i].getCell(row2));
    m[i].setCell(row2, this->_m[i].getCell(row1));
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
 */
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