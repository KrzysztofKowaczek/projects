#include "Matrix.hh"
#include "Size.hh"
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Matrix, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

double Matrix::getCell(unsigned int row, unsigned int col) const
{
  if(row < SIZE && col < SIZE)
    return this->_m[row][col];
  else
    return 0;
}

int Matrix::writeCell(unsigned int row, unsigned int col, const double &value)
{
  if(row < SIZE && col < SIZE)
    this->_m[row][col] = value;
  else
    return 0;
  return 1;
}

Matrix::Matrix()
{
  for(int i = 0; i < SIZE; i++)
    for(int j = 0; j < SIZE; j++)
      _m[i][j] = 0;
}

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