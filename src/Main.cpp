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

	vector< vector<double> > passMatrix = {{1,2,3,4},{7,8,9,10},{12,25,36,42},{12,56,33,78}};
	vector<double> passVector = {1,2,7,9};
	vector<double> passVector2 = {1,2,7,8};


	Matrix<double> myMatrix;
	myMatrix.setMatrix(passMatrix);
	myMatrix.printInfo();
	myMatrix.setMatrix(passVector);
	myMatrix.printInfo();

	MatrixEquation<double> myEquation;
	myEquation.setEquation(passMatrix, passVector);
	//myEquation.setEquation(passMatrix, passVector2);
	myEquation.solvingLU();
	myEquation.printInfo();




	return 0;
}
