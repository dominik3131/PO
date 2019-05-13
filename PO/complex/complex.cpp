#include "complex.h"
#include <iostream>
#include <cmath>

using namespace std;
//<------------------------------------------------------------------------->  
Complex::~Complex()
{
}
//<------------------------------------------------------------------------->
Complex::Complex ():Real (0), Imag (0)
{
}
//<------------------------------------------------------------------------->
Complex::Complex (double co)
{
    this->Real = co;
    this->Imag = 0;
}
//<------------------------------------------------------------------------->  
Complex::Complex (double Real, double Imag)
{
	this->Real = Real;
	this->Imag = Imag;
} 

//<------------------------------------------------------------------------->
double Complex::real() const
{
	return this->Real;
} 
//<------------------------------------------------------------------------->
double Complex::imag() const
{
	return this->Imag;
}
//<------------------------------------------------------------------------->
double Complex::argz() const
{	
	if(this->Real==0&&this->Imag==0)
	{
		cout<<endl<<"not possible to calculate, 0 was returned"<<endl;
	}
	else if(this->Real>0) return atan2(this->Imag,this->Real);
	else if(this->Real<0&&this->Imag>=0) return atan2(this->Imag,this->Real)+M_PI;
	else if(this->Real<0&&this->Imag<0) return atan2(this->Imag,this->Real)-M_PI;
	else
	{
		if(this->Imag>0) return	M_PI/2;
		else return	-M_PI/2;
	}
}
//<------------------------------------------------------------------------->
double Complex::amp() const
{
	return sqrt(this->Real*this->Real+this->Imag*this->Imag);
}
//<------------------------------------------------------------------------->
Complex Complex::operator-()const 
{
	return Complex(-Real,-Imag);
}
//<------------------------------------------------------------------------->
Complex Complex::operator= (const Complex& s2)
{
	this->Real=s2.Real;
	this->Imag=s2.Imag;
	return *this;
}
//<------------------------------------------------------------------------->
Complex & Complex::operator+= (const Complex & co)
{
   	this->Real += co.Real;
   	this->Imag += co.Imag;
   	return *this;
}
//<------------------------------------------------------------------------->
Complex & Complex::operator-= (const Complex & co)
{	
    Real -= co.Real;
    Imag -= co.Imag;
    return *this;
}
//<------------------------------------------------------------------------->
Complex & Complex::operator*= (const Complex & co)
{
	*this = *this * co;
    return *this;
  	}
//<------------------------------------------------------------------------->
Complex & Complex::operator/= (const Complex & co)
{
	*this = *this / co;
    return *this;
}
//<------------------------------------------------------------------------->
bool operator== (const Complex & s1,const Complex & s2)
{
	if(s1.Real==s2.Real&&s1.Imag==s2.Imag) return true;
	else return false;
}
//<------------------------------------------------------------------------->
Complex operator + (const Complex& s1, const Complex& s2)
{
  Complex n (s1);
  return n += s2;
}
//<------------------------------------------------------------------------->
Complex operator - (const Complex& s1, const Complex& s2)
{
  Complex n (s1);
  return n -= s2;
}
//<------------------------------------------------------------------------->
Complex operator * (const Complex& s1, const Complex& s2)
{
  Complex n;
  n.Real=s1.Real*s2.Real-s1.Imag*s2.Imag;
  n.Imag=s1.Real*s2.Imag+s1.Imag*s2.Real;
  return n;
}
//<------------------------------------------------------------------------->
Complex operator / (const Complex& s1, const Complex& s2)
{
  	Complex n;
	n.Real = (s1.Real*s2.Real+s1.Imag*s2.Imag)/(s2.Real*s2.Real+s2.Imag*s2.Imag);
	n.Imag = (s1.Imag*s2.Real-s1.Real*s2.Imag)/(s2.Real*s2.Real+s2.Imag*s2.Imag);
  	return n;
}
//<------------------------------------------------------------------------->

//<------------------------------------------------------------------------->
 ostream & operator << (ostream & s, const Complex & c) 
{
    s << "(" << c.Real << "," << c.Imag << ")";
    return s;
} 
