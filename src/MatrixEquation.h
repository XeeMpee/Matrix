/*
 * MatrixEquatiom.h
 *
 *  Created on: 4 maj 2018
 *      Author: xeempee
 */

#ifndef MATRIXEQUATION_H_
#define MATRIXEQUATION_H_

#include "Matrix.h"
#include <iostream>
#include <vector>

#include "MatrixException.h"
using namespace std;

template<class T>
class MatrixEquation {
public:
	MatrixEquation();
	virtual ~MatrixEquation();

private:
	//# Equations Ax=b:
	Matrix<T> A;
	Matrix<T> x;
	Matrix<T> b;

	//# Flags:
	bool changedA;

	//#Gauss (LU):
	Matrix<T> gaussUpper;
	Matrix<T> gaussLower;

public:
	//# Setters and getters:
	void setEquation(vector<vector<T> > A, vector<T> b);

	//# Solving:
	Matrix<T> solvingLU();
	Matrix<T> upperMatrixSolving();

	//# PrintOuts:
	void printInfo();

};

//#  --------------------------------- DEFINICJE: ----------------------------------
//#  Constructs, destructors:
template<class T>
MatrixEquation<T>::MatrixEquation() {
	this->changedA = false;
}

template<class T>
MatrixEquation<T>::~MatrixEquation() {

}

//# Set Equation:
template<class T>
void MatrixEquation<T>::setEquation(vector<vector<T> > A, vector<T> b) {

	if (A.size() != b.size()) {
		MatrixSizeException exception(
				"Matrix A and b vect should have the same number of rows!");
		exception.showDescription();
		throw exception;
	}

	this->A.clear();
	this->b.clear();
	this->x.clear();

	this->A.setMatrix(A);
	this->b.push(b);

	this->changedA = true;
}

//# LU:
template<class T>
	Matrix<T> MatrixEquation<T>::solvingLU() {
	Matrix<T> tmpUpper = this->A;
	Matrix<T> tmpLower;
	T tmpCoeff;


	for(int i=0; i< this->A.size[1]; i++){
		for(int j=i+1; j < this->A.size[0]; j++){
			tmpCoeff = tmpUpper[j][i] / tmpUpper[i][i];
			tmpUpper[j] = Matrix<T>::substractRows(tmpUpper[j], tmpUpper[i], tmpCoeff);
			}
		cout << endl;
	}


	this->gaussUpper = tmpUpper;
	this->gaussLower = tmpLower;
	return tmpUpper;
}

//# UpperMatrix solving:

//# PrintOuts:
template<class T>
void MatrixEquation<T>::printInfo() {
	cout << "Matrix A: " << endl;
	this->A.printInfo();
	cout << "Vector x: " << endl;
	this->b.printInfo();
	cout << "UpperMatrix: " << endl;
	this->gaussUpper.printInfo();
	cout << "LowerMatrix: " << endl;
	this->gaussLower.printInfo();
}

#endif /* MATRIXEQUATION_H_ */
