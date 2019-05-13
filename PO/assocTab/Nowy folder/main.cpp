#include <iostream>
#include <ctype.h>
#include <string.h>
using namespace std;
#include "assoctab.h"

int main(int argc, char** argv) {
	assocTabNDL a, b;
	a["aa"]=564;
	a["aaasdaa"]=554664;
	a["aAaa"]=1;
	a["aaaa"]=2;
	a["aaasd"]=512312364;
	b=a;
	assocTabNDL c(a);

	cout<<a["aaAA"];
	assocTabDL d, g;
	d["aa"]=564;
	g["aaasdaa"]=554664;
	d["aAaa"]=1;
	cout<<d["aAaa"];

	
	return 0;
}
