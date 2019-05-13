#ifndef __Complex_H__
#define __Complex_H__
#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
private:
  private:
  double Real, Imag;
public:
	~Complex();
    Complex ();
	Complex (double);
  	Complex (double, double);
	double real()const;
	double imag()const;
	double argz()const;
	double amp()const;
  	Complex operator-() const;
  	Complex operator= (const Complex&);
  	Complex & operator+= (const Complex & );
  	Complex & operator-= (const Complex & );
  	Complex & operator*= (const Complex & );
  	Complex & operator/= (const Complex & );
  	friend bool operator== (const Complex &,const Complex & );
  	friend Complex operator+ (const Complex&, const Complex&);
  	friend Complex operator- (const Complex&, const Complex&);
  	friend Complex operator* (const Complex&, const Complex&);
  	friend Complex operator/ (const Complex&, const Complex&);
  	friend ostream & operator << (ostream &, const Complex &);
 
};

  



#endif /* __Complex_H__ */
