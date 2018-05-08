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
#include "MatrixException.h"
#include "MatrixEquation.h"

using namespace std;

int main() {
	cout << "!!!Hello Darkness, my old friend!!!" << endl << endl; // prints !!!Hello World!!!

	vector< vector<double> > passMatrix = {{1,2,3},{4,7,1},{2,5,5}};
	vector<double> passVector = {3,4,2};
	vector<double> passVector2 = {1,2,7};


	MatrixEquation<double> myEquation;
	myEquation.setEquation(passMatrix, passVector);
	myEquation.solvingLU();
	myEquation.printInfo();
	myEquation.setB(passVector2);
	myEquation.solvingLU();
	myEquation.printInfo();




	return 0;
}
