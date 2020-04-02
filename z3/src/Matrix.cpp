#include "Matrix.hh"
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
 *          row i col nie moga byc wieksze niz stopien macierzy - 1.
 * Zwraca:
 *          Wartosc komorki macierzy.
 */
double Matrix::getCell(unsigned int row, unsigned int col) const
{
  if(row < SIZE && col < SIZE)
    return this->_m[row][col];
  else
    return 0;
}

/*
 * Metoda interfejsu Matrix, daje mozliwosc zapisu do komorki macierzy
 * Argumety:
 *          row - wiersz macierzy (0 odnosi sie do 1 wierszu),
 *          col - kolumna macierzy (0 odnosi sie do 1 kolumny),
 *          value - wartosc do przypisania do komorki
 * Warunki wstepne:
 *          row i col nie moga byc wieksze niz stopien macierzy - 1.
 * Zwraca:
 *          1 jesli podano dobre row i col, 0 w przeciwnym przypadku.
 */
int Matrix::writeCell(unsigned int row, unsigned int col, const double &value)
{
  if(row < SIZE && col < SIZE)
    this->_m[row][col] = value;
  else
    return 0;
  return 1;
}

/*
 * Konstruktor macierzy, inicjalizuje ja zerami.
 */
Matrix::Matrix()
{
  for(int i = 0; i < SIZE; i++)
    for(int j = 0; j < SIZE; j++)
      _m[i][j] = 0;
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
 for(int i = 1; i < SIZE + 1; i++)
 {
    for(int j = 1; j < SIZE + 1; j++)
      stream << matrix.getCell(i, j) << " ";
    stream << std::endl;
 }
  return stream;
}
