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
	Matrix<T> gaussB;
	Matrix<T> gaussX;

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
	Matrix<T> tmpLower(this->A.size[0], this->A.size[1], 0);
	T tmpCoeff;


	for(int i=0; i< tmpUpper.size[1]; i++){
		vector<T> coeffVect;
		for(int j=i+1; j < tmpUpper.size[0]; j++){
			if(tmpUpper[i][i] == 0){
				int myMax = tmpUpper.maxInColumnIndex(i);
				cout << myMax;
				vector<T> tmpVect = tmpUpper[i];
				tmpUpper[i] = tmpUpper[myMax];
				tmpUpper[myMax] = tmpVect;
				j--;
				continue;
			}

			tmpCoeff = tmpUpper[j][i] / tmpUpper[i][i];
			tmpLower[j][i] = tmpCoeff;
			tmpUpper[j] = Matrix<T>::substractRows(tmpUpper[j], tmpUpper[i], tmpCoeff);
			tmpUpper[j][i] = 0;
		}
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
