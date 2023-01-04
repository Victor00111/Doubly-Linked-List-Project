/*
 * MainDLL.cpp
 *
 *      Author: 13027
 */


#include "Coder.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

void valuefunc(int x);  
// for your edification, nothing to do with lab, but see how this works!
void referencefunc(int &x);
// see above
void pointerfunc(int *x);
// see above

int main() {
	Coder code;
//	int k = 2;
//	valuefunc(k);
//	cout << k << endl;
//	k = 5;
//	referencefunc(k);
//	cout << k << endl;
//	k = 1;
//
//	pointerfunc(&k);
//	cout << k << endl;
	return 0;
}

void valuefunc(int x) {
	x += 3;
}
void referencefunc(int &x) {
	x += 3;
}
void pointerfunc(int *x) {
	*x += 3;
}
