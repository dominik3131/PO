#include <iostream>
#include "matrix.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	rcMatrix m1(2,4,0.0);
	
cout<<m1;
try{
m1.loadFile("m1.txt");	
}
catch(rcMatrix::errorOpeningFile){
	cout<<"das";
}
catch(std::bad_alloc){
	cout<<"daass";
}

cout<<m1;

	return 0;
}
