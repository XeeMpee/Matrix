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
	void setEquation(vector<vector<T> > A, vector<T>  b);

	//# Solving:
	Matrix<T> solvingLU();
	Matrix<T> upperMatrixSolving();

	//# PrintOuts:
	void printInfo();

};


//#  --------------------------------- DEFINICJE: ----------------------------------
//#  Constructs, destructors:
template<class T>
MatrixEquation<T>::MatrixEquation(){
	this->changedA = false;
}

template<class T>
MatrixEquation<T>::~MatrixEquation(){

}

//# Set Equation:
template<class T>
void MatrixEquation<T>::setEquation(vector<vector<T> > A, vector<T>  b){

	if(A.size() != b.size()){
		MatrixSizeException exception("Matrix A and b vect should have the same number of rows!");
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
Matrix<T> MatrixEquation<T>::solvingLU(){
	Matrix<T> tmpUpper;
	Matrix<T> tmpLower;
	T tmpCoeff;

	tmpUpper.push(this->A[0]);
	for(int i=1; i< this->A.size[0]; i++){
		tmpCoeff = this->A[i][0] / tmpUpper[0][0];
		vector<T> tmpVect = Matrix<T>::substractRows(this->A[i], this->A[0], tmpCoeff);
		cout << tmpVect[0] << tmpVect[1] << tmpVect[3] << endl;
		tmpUpper.push(tmpVect);
	}

	this->gaussUpper = tmpUpper;
	this->gaussLower = tmpLower;
	return tmpUpper;
}


//# UpperMatrix solving:

//# PrintOuts:
template<class T>
void MatrixEquation<T>::printInfo(){
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
