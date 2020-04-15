#include "Vector.hh"

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
 * 
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
  for(int i = 0; i < SIZE; i++)
    stream << vec.getCell(i) << " ";
  return stream;
}

/*
 * Przeciazenie operatora + dla klasy Vector
 * 
 */
Vector operator + (const Vector &vec1, const Vector &vec2)
{
  Vector result;
  for(int i = 0; i < SIZE; i++)
    result.setCell(i, vec1.getCell(i) + vec2.getCell(i));

  return result;
}

/*
 * Przeciazenie operatora - dla klasy Vector
 * 
 */
Vector operator - (const Vector &vec1, const Vector &vec2)
{
  Vector result;
  for(int i = 0; i < SIZE; i++)
    result.setCell(i, vec1.getCell(i) - vec2.getCell(i));

  return result;
}

/*
 * Przeciazenie operatora & dla klasy Vector. Realizuje mnozenie skalarne.
 * 
 */
double operator & (const Vector &vec1, const Vector &vec2)
{
  double result = 0;
  for(int i = 0; i < SIZE; i++)
    result += vec1.getCell(i) * vec2.getCell(i);
  
  return result;
}

/*
 * Przeciazenie operatora * dla klasy Vector
 * 
 */
Vector operator * (const Vector &vec, double val)
{
  Vector result;
  for(int i = 0; i < SIZE; i++)
    result.setCell(i, vec.getCell(i) * val);
  
  return result;
}

/*
 * Przeciazenie operatora / dla klasy Vector
 * 
 */
Vector operator / (const Vector &vec, double val)
{
  Vector result;
  if(val == 0)
    return result;
  for(int i = 0; i < SIZE; i++)
    result.setCell(i, vec.getCell(i) / val);
  
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