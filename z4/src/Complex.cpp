#include <iostream>
#include "Complex.hh"
#include <cmath>

constexpr double ERR_MARGIN = 0.0000001;

double Complex::module() const
{
	return sqrt(this->re*this->re + this->im*this->im);
}


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    arg1 - pierwszy skladnik dodawania,
 *    arg2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
Complex operator + (const Complex &arg1, const Complex &arg2)
{
    Complex result;

    result.re = arg1.re + arg2.re;
    result.im = arg1.im + arg2.im;
    return result;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *      arg1 - pierwszy skladnik odejmowania,
 *      arg2 - drugi skladnik odejmowania.
 * Zwraca:
 *      Zwraca roznice dwoch skladnikow przekazanych jako parametry.
 */ 
Complex operator - (const Complex &arg1, const Complex &arg2)
{
    Complex result;

    result.re = arg1.re - arg2.re;
    result.im = arg1.im - arg2.im;
    return result;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *      arg1 - pierwszy skladnik mnozenia,
 *      arg2 - drugi skladnik mnozenia.
 * Zwraca:
 *      Zwraca iloczyn dwoch skladnikow przekazanych jako parametry.
 */ 
Complex operator * (const Complex &arg1, const Complex &arg2)
{
    Complex result;

    result.re = (arg1.re * arg2.re) - (arg1.im * arg2.im);
    result.im = (arg1.re * arg2.im) + (arg1.im * arg2.re);
    return result;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *      arg1 - pierwszy skladnik dzielenia,
 *      arg2 - drugi skladnik dzielenia.
 * Warunki wstepne:
 *      - arg2 nie moze byc zerowy. Gdy jednak bedzie, to funkcja
 *        zwroci arg1 i komunikat na cerr.
 * Zwraca:
 *      Zwraca iloraz dwoch skladnikow przekazanych jako parametry.
 */ 
Complex operator / (const Complex &arg1, const Complex &arg2)
{
    Complex result;
    double absSq = AbsSquared(arg2);
    result = (arg1 * Conjugate(arg2)) / absSq;
    
    if(result.im*result.im < ERR_MARGIN)
        result.im = 0;
    if(result.re*result.re < ERR_MARGIN)
        result.re = 0;

    return result;
}

/*!
 * Realizuje dzielenie liczby zespolonej i rzeczywistej.
 * Argumenty:
 *      arg1 - liczba zespolona,
 *      arg2 - liczba rzeczywista.
 * Zwraca:
 *      Zwraca iloraz dwoch skladnikow przekazanych jako parametry.
 */ 
Complex operator / (const Complex &arg1, const double &arg2)
{
    Complex result = arg1;
    result.re /= arg2;
    result.im /= arg2;
    return result;
}

/*!
 * Porownuje dwie liczby zespolone
 * Argumenty:
 *      arg1 - pierwsza liczba zespolona,
 *      arg2 - druga liczba zespolona.
 * Zwraca:
 *      Zwraca:
 *      true - liczby sa rowne,
 *      false - liczby nie sa rowne.
 */ 
bool operator == (const Complex &arg1, const Complex &arg2)
{
    if(abs(arg1 - arg2) < ERR_MARGIN)
        return 1;
    else 
        return 0;
}

/*!
 * Wczytuje pojedyncza liczbe zespolona w postaci (x+yi).
 * Argumenty:
 *      in - strumien wejsciowy,
 *      c - liczba zespolona.
 * Zwraca:
 *      Zwraca strumien wejsciowy.
 */
std::istream & operator >> (std::istream &in, Complex &c)
{
    Complex temp;
    
    /*bool allgood = true;
    char d1 = 0, d2 = 0, d3 = 0;
    double x1 = 0, x2 = 0;

    in >> d1;
    if(d1 != '(')
        allgood = false;
    else
    {
        in >> x1;
        if(in.fail())
        {
            in.clear();
            in >> d1;
            if(d1 == 'i')
            {  
                in >> d2;
                if(d2 == ')')
                {
                    temp.re = 0;
                    temp.im = 1;
                }
            }
            else if(d1 == '-')
            {
                in >> d2 >> d3;
                if(d2 == 'i' && d3 == ')')
                {
                    temp.re = 0;
                    temp.im = -1;
                }
            }
            else 
                allgood = false;
        }
        else
        {
            in >> x2;
            if(in.fail())
            {   
                in.clear();
                in >> d1;
                if(d1 == '-' || d1 == '+')
                {
                    in >> d2 >> d3;
                    if(d2 == 'i' && d3 == ')')
                    {
                        temp.re = x1;
                        if(d1 == '-')
                            temp.im = -1;
                        else
                            temp.im = 1;
                    }
                }
                else if(d1 == 'i')
                {
                    in >> d2;
                    if(d2 == ')')
                    {
                        temp.re = 0;
                        temp.im = x1;
                    }
                    else
                        allgood = false;
                }
                else if(d1 == ')')
                {
                    temp.re = x1;
                    temp.im = 0;
                }
                else
                    allgood = false;
            }
        }
    }
    if(allgood)
        c = temp;
    else
    {
        in >> x1 >> x2;
        std::cerr << std::endl << "Blad zapisu liczby zespolonej!" 
            << std::endl << std::endl;
    }*/
    char c1, c2, c3;
    in >> c1 >> temp.re >> temp.im >> c2 >> c3;
    if(c1 == '(' && c2 == 'i' && c3 == ')')
        c = temp;
    return in;
}


/*!
 * Wyswietla pojedyncza liczbe zespolona w postaci (x+yi).
 * Argumenty:
 *      out - strumien wyjsciowy,
 *      c - liczba zespolona.
 * Zwraca:
 *      Zwraca strumien wyjsciowy.
 */
std::ostream & operator << (std::ostream &out, const Complex &c)
{
    if(c.im < 0)
        out << "(" << c.re << c.im << "i" << ")";
    else
        out << "(" << c.re << "+" << c.im << "i" << ")";
    
    return out;
}

/*!
 * Realizuje sprzezenie liczby zespolonej.
 * Argumenty:
 *      c - liczba zespolona do sprzezenia.
 * Zwraca:
 *      Zwraca sprzezona liczbe zespolona.
 */
Complex Conjugate(Complex c)
{
    c.im *= -1;
    return c;
}

/*!
 * Liczy kwadrat modulu liczby zespolonej.
 * Argumenty:
 *      c - liczba zespolona.
 * Zwraca:
 *      Zwraca podniesiony do kwadratu modul liczby zespolonej.
 */
double AbsSquared(Complex c)
{
    double result = (c.re * c.re) + (c.im * c.im);
    return result;
}

double abs(Complex c)
{
	return c.module();
}

void Complex::operator*=(const Complex &c)
{
    *this = *this * c;
}

void Complex::operator=(const int val)
{
    this->re = val;
    this->im = 0;
}