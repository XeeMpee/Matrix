//============================================================================
// Name        : Matrix.cpp
// Author      : XeeMpee
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Matrix.h"
using namespace std;

int main() {
	cout << "!!!Hello Darkness, my old friend!!!" << endl << endl; // prints !!!Hello World!!!

	vector< vector<double> > passMatrix = {{1,2,3},{7,8,9},{3,3,3}};

	Matrix<double> myMatrix;
	myMatrix.setMatrix(passMatrix);
	myMatrix.printInfo();

	return 0;
}
