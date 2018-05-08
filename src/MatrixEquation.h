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
	static Matrix<T> upperMatrixSolving(Matrix<T>& upperMatrix, Matrix<T>& b);

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

	gaussUpper = this->A;
	gaussLower.setMatrix(this->A.size[0], this->A.size[1], 0);
	gaussB = this->b;
	T tmpCoeff;


	for(int i=0; i< gaussUpper.size[1]; i++){
		vector<T> coeffVect;
		for(int j=i+1; j < gaussUpper.size[0]; j++){
			if(gaussUpper[i][i] == 0){
				int myMax = gaussUpper.maxInColumnIndex(i);

				vector<T> tmpVect = gaussUpper[i];
				gaussUpper[i] = gaussUpper[myMax];
				gaussUpper[myMax] = tmpVect;

				double tmpDouble = gaussB[0][i];
				gaussB[0][i] = 	gaussB[0][myMax];
				gaussB[0][myMax] = tmpDouble;

				j--;
				continue;
			}

			tmpCoeff = gaussUpper[j][i] / gaussUpper[i][i];
			gaussLower[j][i] = tmpCoeff;
			gaussUpper[j] = Matrix<T>::substractRows(gaussUpper[j], gaussUpper[i], tmpCoeff);
			gaussB[0][j] -= gaussB[0][i]*tmpCoeff;
			gaussUpper[j][i] = 0;
		}
	}

	this->x = upperMatrixSolving(gaussUpper, gaussB);
	return this->x;
}

//# UpperMatrix solving:

template<class T>
Matrix<T> MatrixEquation<T>::upperMatrixSolving(Matrix<T>& upperMatrix, Matrix<T>& b){

	vector<T> resultVect;
	int n = upperMatrix.size[0]-1;

	T x = b[0][n]/upperMatrix[n][n];
	resultVect.push_back(x);
	for(int i= n-1; i >= 0; i--){
		T tmp = 0;
		for(int j = i+1; j<=n; j++){
			tmp += upperMatrix[i][j]*resultVect[n-j];
		}
		x = (b[0][i] - tmp) / upperMatrix[i][i];
		resultVect.push_back(x);
	}

	Matrix<T> retMatrix;
	retMatrix.push(resultVect);
	return retMatrix;

}

//# PrintOuts:
template<class T>
void MatrixEquation<T>::printInfo() {
	cout << "Matrix A: " << endl;
	this->A.printInfo();
	cout << "Matrix b: " << endl;
	this->b.printInfo();
	cout << "Vector x: " << endl;
	this->x.printInfo();
	cout << "UpperMatrix: " << endl;
	this->gaussUpper.printInfo();
	cout << "LowerMatrix: " << endl;
	this->gaussLower.printInfo();
	cout << "GaussB: " << endl;
	this->gaussB.printInfo();
}

#endif /* MATRIXEQUATION_H_ */
