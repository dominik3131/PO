#include <iostream>
#include <math.h>
#include "Complex.h"
using namespace std;

Complex::Complex ():Real (0), Imag (0)
{
}

Complex::Complex (double co)
{
   Real = co;
    Imag = 0;
}

Complex::Complex (double Real, double Imag)
{
   this->Real = Real;
   this->Imag = Imag; 
}

Complex &Complex::operator= (const Complex & s)
{
    Real = s.Real;
    Imag = s.Imag;
    return *this;
}

Complex &Complex::operator= (double co)
{
    Real = co;
    Imag = 0;
    return *this;
}

Complex Complex::operator- () const
{
   return Complex(-Real,-Imag);
}

Complex& Complex ::operator/= (Complex s1)
{
     *this = *this / s1;
     return *this;
}

Complex& Complex::operator*= (Complex s1)
{
     *this = *this * s1;
     return *this;
}

Complex & Complex::operator+= (Complex co)
{
  	cout<< "&operator +=";
    Real += co.Real;
    Imag += co.Imag;
    return *this;
}

Complex & Complex::operator-= (Complex co)
{
    Real -= co.Real;
    Imag -= co.Imag;
    return *this;
}
Complex operator + (Complex s1, Complex s2)
{
    cout<< "inline +";
    Complex n (s1);
    return n += s2;
}

Complex operator - (Complex s1, Complex s2)
{
    cout<< "inline -";
    Complex n (s1);
    return n -= s2;
}
Complex operator* (const Complex& s1,const Complex& s2)
{
    Complex n;
    n.Real = s1.Real * s2.Real - s1.Imag*s2.Imag;
    n.Imag = s1.Imag * s2.Real + s1.Real*s2.Imag;
    return n;
}
 Complex operator/ (const Complex& s1,const Complex& s2)
{
    Complex n,tmp(s2.Real,-s2.Imag);
    n = s1*tmp;  
    double x = s2.Real*s2.Real+ s2.Imag*s2.Imag;
    n.Real = n.Real /x;
	n.Imag = n.Imag /x; 
    return n;
}
 ostream & operator << (ostream & s, const Complex & c) 
{
    s << "(" << c.Real << "," << c.Imag << ")";
    return s;
} 
double real(const Complex& co)
{
  	 return co.Real;
}

double imag(const Complex& co)
{
  	 return co.Imag;
}
 double phase(const Complex& co)
{
  	return atan2(co.Real,co.Imag);
}
double amp(const Complex& co)
{
  	return sqrt(co.Real*co.Real+co.Imag*co.Imag);
}

bool operator== (const Complex& s1,const Complex& s2)
{
    if(s1.Real != s2.Real)return false;
    if(s1.Imag != s2.Imag)return false;
    else return true;
}

  
