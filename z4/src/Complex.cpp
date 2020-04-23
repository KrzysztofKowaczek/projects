#include <iostream>
#include "Complex.hh"
#include <cmath>

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
    double abs = AbsSquared(arg2);
    if(abs == 0)
    {
        result = arg1;
        std::cerr << "NIE dzielimy przez 0!!!: ";
        return result;
    }

    result = (arg1 * Conjugate(arg2)) / abs;

    if(result.im == 0)
        result.im = 0;
    if(result.re == 0)
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
    if(AbsSquared(arg1 - arg2) < 0.00001)
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
    bool allgood = true;
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
    }
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