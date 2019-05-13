#include <iostream>
using namespace std;
#include "Complex.cpp"


int main()
{
  Complex a(10,2),b(3,4),c;
  //c = 10+b;
  //c= b;
  cout << a <<endl;
  cout << b <<endl;
  //a/=10 ;
  if(3 == a) cout<< "rowne";
  else cout<<"nie ";
  cout << a <<endl;
  cout<<imag(10)<<endl;
  cout<<phase(a)<<endl;
  cout<<amp(a);
}
