#pragma once
#include <iostream>

/*!
 *  Plik zawiera definicje struktury Complex oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */

/*!
 * Modeluje pojecie liczby zespolonej
 */
struct Complex
{
  double re; /*! Pole repezentuje czesc rzeczywista. */
  double im; /*! Pole repezentuje czesc urojona. */
  double module() const;
  void operator*=(const Complex &c);
  void operator*=(const int val)
    {re = re * val; im = im * val;}
  void operator+=(const Complex &c);
  void operator/=(const Complex &c);
  void operator-=(const Complex &c)
    {re = re - c.re; im = im - c.im;}
  void operator=(const int val);
};

/*
 * Przeciazenia operatorow do liczb zespolonych
 */
Complex operator + (const Complex &arg1, const Complex &arg2);
Complex operator - (const Complex &arg1, const Complex &arg2);
Complex operator * (const Complex &arg1, const Complex &arg2);
Complex operator / (const Complex &arg1, const Complex &arg2);
Complex operator / (const Complex &arg1, const double &arg2);
bool operator == (const Complex &arg1, const Complex &arg2);

std::istream & operator >> (std::istream &in, Complex &c);
std::ostream & operator << (std::ostream &out, const Complex &c);


/*
 * Funkcje obliczajace sprzezenie i modul liczby zespolonej
 */
Complex Conjugate(Complex c);
double AbsSquared(Complex c);
double abs(const Complex c);