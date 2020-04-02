#include "Vector.hh"

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Vector, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
double Vector::getCell(unsigned int col) const
{
  if(col < SIZE)
    return this->_v[col];
  else
    return 0;
}

int Vector::writeCell(unsigned int col, const double &value)
{
  if(col < SIZE)
    this->_v[col] = value;
  else
    return 0;
  return 1;
}

Vector::Vector()
{
  for(int i = 0; i < SIZE; i++)
    _v[i] = 0;
}

std::istream &operator>>(std::istream &stream, Vector &vec)
{
  double tmp[SIZE];
  for(int i = 0; i < SIZE; i++)
    stream >> tmp[i];
  if(!stream.fail())
  {
    for(int i = 0; i < SIZE; i++)
      vec.writeCell(i, tmp[i]);
  }
  return stream;
}

std::ostream &operator<<(std::ostream &stream, const Vector &vec)
{
  for(int i = 0; i < SIZE; i++)
    stream << vec.getCell(i) << " ";
  stream << std::endl;
  return stream;
}

Vector operator + (const Vector &vec1, const Vector &vec2)
{
  Vector result;
  for(int i = 0; i < SIZE; i++)
    result.writeCell(i, vec1.getCell(i) + vec2.getCell(i));

  return result;
}

Vector operator - (const Vector &vec1, const Vector &vec2)
{
  Vector result;
  for(int i = 0; i < SIZE; i++)
    result.writeCell(i, vec1.getCell(i) - vec2.getCell(i));

  return result;
}

double operator & (const Vector &vec1, const Vector &vec2)
{
  double result = 0;
  for(int i = 0; i < SIZE; i++)
    result += vec1.getCell(i) * vec2.getCell(i);
  
  return result;
}

Vector operator * (const Vector &vec, double val)
{
  Vector result;
  for(int i = 0; i < SIZE; i++)
    result.writeCell(i, vec.getCell(i) * val);
  
  return result;
}

Vector operator / (const Vector &vec, double val)
{
  Vector result;
  if(val == 0)
    return result;
  for(int i = 0; i < SIZE; i++)
    result.writeCell(i, vec.getCell(i) / val);
  
  return result;
}