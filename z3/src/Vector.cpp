#include "Vector.hh"
#include "math.h"
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Vector, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

/*
 * Metoda interfejsu klasy Vector, daje mozliwosc odczytu komorki wektora.
 * Argumety:
 *          row - wiersz wektora (0 odnosi sie do 1 wierszu).
 * Warunki wstepne:
 *          row nie moze byc wieksze niz stopien wektora - 1.
 * Zwraca:
 *          Wartosc komorki wektora.
 */
double Vector::getCell(unsigned int row) const
{
  if(row < SIZE)
    return this->_v[row];
  else
    return 0;
}

/*
 * Metoda interfejsu klasy Vector, daje mozliwosc odczytu komorki wektora.
 * Argumety:
 *          row - wiersz wektora (0 odnosi sie do 1 wierszu),
 *          value - wartosc do przypisania do komorki.
 * Warunki wstepne:
 *          row nie moze byc wieksze niz stopien wektora - 1.
 * Zwraca:
 *          1 jesli podano dobre row, 0 w przeciwnym przypadku.
 */
int Vector::setCell(unsigned int row, const double &value)
{
  if(row < SIZE)
    this->_v[row] = value;
  else
    return 0;
  return 1;
}

/*
 * Konstrukor klasy Vector, inicjalizuje ja zerami.
 */
Vector::Vector()
{
  for(int i = 0; i < SIZE; i++)
    _v[i] = 0;
}

/*
 * Przeciazenie operatora >> dla klasy Vector
 * Uwaga:
 *        liczby do wczytania powinny być postaci np.:
 *        1 2.7 3.1
 */
std::istream &operator>>(std::istream &stream, Vector &vec)
{
  double tmp[SIZE];
  for(int i = 0; i < SIZE; i++)
    stream >> tmp[i];
  if(!stream.fail())
  {
    for(int i = 0; i < SIZE; i++)
      vec.setCell(i, tmp[i]);
  }
  return stream;
}

/*
 * Przeciazenie operatora << dla klasy Vector
 * 
 */
std::ostream &operator<<(std::ostream &stream, const Vector &vec)
{
  stream << "\t";
  for(int i = 0; i < SIZE; i++)
    stream << vec.getCell(i) << " ";
  return stream;
}

/*
 * Przeciazenie operatora + dla klasy Vector
 * 
 */
Vector Vector::operator + (const Vector &vec) const
{
  Vector result;
  for(int i = 0; i < SIZE; i++)
    result.setCell(i, this->_v[i] - vec.getCell(i));

  return result;
}

/*
 * Przeciazenie operatora - dla klasy Vector
 * 
 */
Vector Vector::operator - (const Vector &vec) const
{
  Vector result;
  for(int i = 0; i < SIZE; i++)
    result.setCell(i, this->_v[i] - vec.getCell(i));

  return result;
}

/*
 * Przeciazenie operatora & dla klasy Vector. Realizuje mnozenie skalarne.
 * 
 */
double Vector::operator & (const Vector &vec) const
{
  double result = 0;
  for(int i = 0; i < SIZE; i++)
    result += this->_v[i] * vec.getCell(i);
  
  return result;
}

/*
 * Przeciazenie operatora * dla klasy Vector
 * 
 */
Vector Vector::operator * (double val) const
{
  Vector result;
  for(int i = 0; i < SIZE; i++)
    result.setCell(i, this->_v[i] * val);
  
  return result;
}

/*
 * Przeciazenie operatora / dla klasy Vector
 * 
 */
Vector Vector::operator / (double val) const
{
  Vector result;
  if(abs(val) < 0.0000001)
    return result;
  for(int i = 0; i < SIZE; i++)
    result.setCell(i, this->_v[i] / val);
  
  return result;
}

void Vector::operator+=(const Vector &vec)
{
  for(int i = 0; i < SIZE; i++)
    this->_v[i] += vec.getCell(i);
}

void Vector::operator-=(const Vector &vec)
{
  for(int i = 0; i < SIZE; i++)
    this->_v[i] -= vec.getCell(i);
}

void Vector::operator*=(double val)
{
  for(int i = 0; i < SIZE; i++)
    this->_v[i] *= val;
}

void Vector::operator/=(double val)
{
  if(val != 0)
    for(int i = 0; i < SIZE; i++)
      this->_v[i] /= val;
}