#include <iostream>
#include "complex.h"
#include <iostream>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Complex a(2,2), b(3,4),c(1,1),d(2,2),e(3,3),f(6,0);
	cout<<" a"<<a<<" b"<<b<<" c"<<c<<endl;
	cout<<" a+b "<<a+b<<endl;
	cout<<" a+10 "<<a+10<<endl;
	cout<<" 10+b "<<10+b<<endl;
	cout<<"<----------------------------->"<<endl;
	cout<<" a-b "<<a-b<<endl;
	cout<<" a-10 "<<a-10<<endl;
	cout<<" 10-b "<<10-b<<endl;
	cout<<"<----------------------------->"<<endl;
	cout<<" a*b "<<a*b<<endl;
	cout<<" a*10 "<<a*10<<endl;
	cout<<" 10*b "<<10*b<<endl;
	cout<<"<----------------------------->"<<endl;
	cout<<" a/b "<<a/b<<endl;
	cout<<" a/10 "<<a/10<<endl;
	cout<<" 10/b "<<10/b<<endl;
	cout<<"<----------------------------->"<<endl;
	cout<<" a"<<a<<" b"<<b<<" c"<<c<<endl;
	a+=b+=c;
	cout<<" a+=b+=c   a"<<a<<endl;
	cout<<"<----------------------------->"<<endl;
	cout<<" a"<<a<<" b"<<b<<" c"<<c<<endl;
	a=b=c;
	cout<<" a=b=c  a"<<a<<endl;
	cout<<"<----------------------------->"<<endl;
	a=b=d;
	c=e;
	cout<<" a"<<a<<" b"<<b<<" c"<<c<<endl;
	a-=b-=c;
	cout<<" a-=b-=c   a"<<a<<endl;
	cout<<"<----------------------------->"<<endl;
	cout<<" a"<<a<<" b"<<b<<" c"<<c<<endl;
	a*=b*=c;
	cout<<" a*=b*=c    a"<<a<<endl;
	cout<<"<----------------------------->"<<endl;
	cout<<" a"<<a<<" b"<<b<<" c"<<c<<endl;
	a/=b/=c;
	cout<<" a/=b/=c    a"<<a<<endl;
	cout<<"<----------------------------->"<<endl;
	a=b=d;
	c=f;
	bool ab,ac,c6;
	ab=(a==b);
	ac=(a==c);
	c6=(c==6);
	cout<<" a"<<a<<" b"<<b<<" c"<<c<<endl;
	cout<<" a==b "<<ab<<endl;
	cout<<" a==c "<<ac<<endl;
	cout<<" c==6 "<<c6<<endl;
	cout<<"<----------------------------->"<<endl;
	cout<<" a"<<a<<endl;
	cout<<" a argz "<<a.argz()<<endl;
	cout<<" a amp "<<a.amp()<<endl;
	return 0;
}

