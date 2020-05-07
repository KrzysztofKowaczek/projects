#pragma once

#include <iostream>

/*
 * Klasa Vector modeluje pojecie wektora wielowymiarowego.
 * Pola:
 *      _v - tablica liczb rzeczywistych stanowiacych wektor.
 */
template <typename T, int  Size>
class Vector
{
private:
  T _v[Size];
  T badIdx;
public:
  Vector() {for(T &type: _v) type = 0;}
  void operator = (T val) {for(T &type: _v) type = val;}
  void operator += (const Vector<T, Size> &vec);
  void operator -= (const Vector<T, Size> &vec);
  void operator *= (T val);
  void operator /= (T val);
  T operator & (const Vector<T, Size> &vec2) const;
  Vector<T, Size> operator + (const Vector<T, Size> &vec2) const;
  Vector<T, Size> operator - (const Vector<T, Size> &vec2) const;
  Vector<T, Size> operator * (T val) const;
  Vector<T, Size> operator / (T val) const;
  T operator[](unsigned int idx) const
		{if(idx < Size) return _v[idx]; return badIdx;}
	T &operator[](unsigned int idx)
		{if(idx < Size) return _v[idx]; return badIdx;}
};


/*
 * Przeciazenie operatora >> dla klasy Vector
 * Uwaga:
 *        liczby do wczytania powinny być postaci np.:
 *        1 2.7 3.1
 */
template<typename T, int Size>
std::istream &operator>>(std::istream &stream, Vector<T, Size> &vect)
{
	Vector<T, Size> tmpV;
	for(int i = 0; i < Size; i++)
		stream >> tmpV[i];
	if(!stream.fail())
		vect = tmpV;
	return stream;
}

/*
 * Przeciazenie operatora << dla klasy Vector
 * 
 */
template<typename T, int Size>
std::ostream &operator<<(std::ostream &stream, const Vector<T, Size> vect)
{
	stream << "\t";
	for(int i = 0; i < Size; i++)
		stream << vect[i] << " ";
	
	stream << std::endl;
	return stream;
}

/*
 * Przeciazenie operatora + dla klasy Vector
 * 
 */
template<typename T, int  Size>
Vector<T, Size> Vector<T,  Size>::operator+(const Vector<T,  Size> &vec) const
{
  Vector<T, Size> result;
  for(int i = 0; i <  Size; i++)
    result[i] = this->_v[i] + vec[i];

  return result;
}

/*
 * Przeciazenie operatora - dla klasy Vector
 * 
 */
template<typename T, int  Size>
Vector<T, Size> Vector<T,  Size>::operator-(const Vector<T,  Size> &vec) const
{
  Vector<T, Size> result;
  for(int i = 0; i <  Size; i++)
    result[i] = this->_v[i] - vec[i];

  return result;
}

/*
 * Przeciazenie operatora & dla klasy Vector. Realizuje mnozenie skalarne.
 * 
 */
template<typename T, int  Size>
T Vector<T, Size>::operator&(const Vector<T,  Size> &vec) const
{
  double result = 0;
  for(int i = 0; i <  Size; i++)
    result += this->_v[i] * vec[i];
  
  return result;
}

/*
 * Przeciazenie operatora * dla klasy Vector
 * 
 */
template<typename T, int  Size>
Vector<T, Size> Vector<T,  Size>::operator*(T val) const
{
  Vector<T, Size> result;
  for(int i = 0; i <  Size; i++)
    result[i] = this->_v[i] * val;
  
  return result;
}

/*
 * Przeciazenie operatora / dla klasy Vector
 * 
 */
template<typename T, int  Size>
Vector<T, Size> Vector<T,  Size>::operator/(T val) const
{
  Vector<T,  Size> result;
  if(abs(val) < 0.0000001)
    return result;
  for(int i = 0; i <  Size; i++)
    result[i] = this->_v[i] / val;
  
  return result;
}

template<typename T, int  Size>
void Vector<T, Size>::operator+=(const Vector<T,  Size> &vec)
{
  for(int i = 0; i <  Size; i++)
    this->_v[i] += vec[i];
}

template<typename T, int  Size>
void Vector<T, Size>::operator-=(const Vector<T,  Size> &vec)
{
  for(int i = 0; i <  Size; i++)
    this->_v[i] -= vec[i];
}

template<typename T, int  Size>
void Vector<T, Size>::operator*=(T val)
{
  for(int i = 0; i <  Size; i++)
    this->_v[i] *= val;
}

template<typename T, int  Size>
void Vector<T,  Size>::operator/=(T val)
{
  if(!(val == 0))
    for(int i = 0; i <  Size; i++)
      this->_v[i] /= val;
}

using Vector3D = Vector<double, 3>;