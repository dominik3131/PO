#ifndef __Complex_H__
#define __Complex_H__
#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
private:
  double Real, Imag;
public:
    Complex ();
    Complex (double);
    Complex (double, double);
    Complex & operator= (const Complex &);
	Complex & operator= (double);
    Complex operator- () const;
	friend Complex operator* (const Complex& ,const Complex&);
    friend Complex operator/ (const Complex&,const Complex&);
    friend bool operator== (const Complex&,const Complex& );
    Complex &operator/= (Complex);
    Complex &operator*= (Complex );
	Complex & operator+= (Complex );
    Complex & operator-= (Complex );
    friend Complex operator + (Complex , Complex );
    friend Complex operator - (Complex , Complex );
    friend ostream & operator << (ostream & , const Complex & ) ;
    friend double real(const Complex&);
    friend double imag(const Complex&);
    friend double phase(const Complex&);
    friend double amp(const Complex&);
};
#endif /* __Complex_H__ */
