#include <iostream>
#include "vector.h"

using namespace std;
int main(int argc, char** argv) {
	Vect v1(3);
	v1.setElement(0,0.5);
	v1.setElement(1,1.5);
	v1.setElement(2,2.5);

	cout<<v1<<endl;
	cout<<v1.getSize()<<endl;
	cout<<v1.getAverage()<<endl;

	Vect v2(2);
	v2.setElement(0,0.1);
	v2.setElement(1,-0.2);

	cout<<v2<<endl;
	cout<<v2.getSize()<<endl;
	cout<<v2.getAverage()<<endl;

	cout<<v1.getMin()<<endl;
	cout<<v2.getMin()<<endl;
	try{
		v2.setElement(2,-0.2);
	}

	catch(Vect::outOfRange){
		cout<<"indeks poza zakresem"<<endl;
	}

	Vect v3=(v1+v2);
	cout<<v3<<endl;
	return 0;
}
