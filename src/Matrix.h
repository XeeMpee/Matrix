/*
 * Matrix.h
 *
 *  Created on: 4 maj 2018
 *      Author: xeempee
 */

#ifndef MATRIX_H_
#define MATRIX_H_
#include<iostream>
#include<vector>
#include <typeinfo>
#include "MatrixException.h"
using namespace std;

template<class T>
class Matrix {
public:
	Matrix();
	Matrix(vector<vector<T> > passMatrix);
	virtual ~Matrix();
	int size[2];
private:
	//# Pure Matrix:
	vector<vector<T> > matrix;


public:
	//# Setters, getters:
	void setMatrix(vector<vector<T> > passMatrix);
	void setMatrix(vector<T> passVector);
	T getMatrix();

	//# Basic operations:
	void clear();
	void push(vector<T> pushVector);

	//# Operations on matrices:

	//# Another operations:
	static vector<T> multiplyByCoeff(vector<T> rowOne, T coeff);
	static vector<T> substractRows(vector<T> rowOne, vector<T> rowTwo, T coeff);

	//# Overload operatos:
	Matrix<T> & operator= (vector<vector<T> > & passMatrix);
	vector<T> operator[](size_t el);

	//# PrintOuts:
	void printInfo();
};

//#  --------------------------------- DEFINICJE: ----------------------------------
//# Constructors, destructors:
template<class T>
inline Matrix<T>::Matrix(vector<vector<T> > passMatrix) {
	this->size[0] = this->matrix.size();
	this->size[1] = this->matrix[0].size();
	this->matrix = passMatrix;
}

template<class T>
inline Matrix<T>::Matrix() {

	this->matrix.clear();
	this->size[0] = 0;
	this->size[1] = 0;
}

template<class T>
inline Matrix<T>::~Matrix() {

}

//# Set matrix:
template<class T>
inline void Matrix<T>::setMatrix(vector<vector<T> > passMatrix) {
	this->matrix.clear();
	this->matrix = passMatrix;
	this->size[0] = this->matrix.size();
	this->size[1] = this->matrix[0].size();
}

template<class T>
inline void Matrix<T>::setMatrix(vector<T> passVector) {
	this->matrix.clear();
	this->matrix.push_back(passVector);
	this->size[0] = this->matrix.size();
	this->size[1] = this->matrix[0].size();
}

//# Basic operations:
template<class T>
inline void Matrix<T>::clear(){
	this->matrix.clear();
	this->size[0] = 0;
	this->size[1] = 0;
}

template<class T>
inline void Matrix<T>::push(vector<T> pushVector){
	if(this->size[0] == 0){
		this->size[1] = pushVector.size();
	}

	if(this->size[0] != 0){
		if(pushVector.size() != (unsigned int)this->size[1]){
			MatrixSizeException exception("Vector should be thi same size as the rest of vectors in Matrix (rows)!");
			exception.showDescription();
			throw exception;
		}
	}


	this->matrix.push_back(pushVector);
	this->size[0] += 1;

}

//# Another operations:
template<class T>
inline vector<T> Matrix<T>::multiplyByCoeff(vector<T> rowOne, T coeff ){
	vector<T> retVect;
	for(T i : rowOne){
		retVect.push_back(i * coeff);
	}
	return retVect;
}

template<class T>
vector<T> Matrix<T>::substractRows(vector<T> rowOne, vector<T> rowTwo, T coeff){
	/* Returns rowOne - coeff*rowTwo */

	if(rowOne.size() != rowTwo.size()){
		MatrixSizeException exception("RowOne size diffrent thant rowTwo size - substracting unaviable!");
		exception.showDescription();
		throw exception;
	}

	vector<T> retVect;
	if(coeff != 1){
		rowTwo = Matrix<T>::multiplyByCoeff(rowTwo, coeff);
	}

	for(unsigned int i=0; i<rowOne.size(); i++){
		retVect.push_back(rowOne[i] - rowTwo[i]);
	}

	return retVect;
}

//# Overload operators:
template<class T>
inline Matrix<T>&  Matrix<T>::operator= (vector<vector<T> > & passMatrix){
	this->matrix = passMatrix;
	return *this;
}

template<class T>
inline vector<T> Matrix<T>::operator[](size_t el){
	return this->matrix[el];
}

//# Print info about matrix:
template<class T>
inline void Matrix<T>::printInfo() {
	enum type {
		matrixType, vectorType
	};
	type type;
	if (this->size[0] > 1)
		type = matrixType;
	else
		type = vectorType;

	if (type == matrixType) {
		cout << "Matrix:" << endl;
		for (vector<T> j : this->matrix) {
			for (T k : j) {
				cout << k << " ";
			}
			cout << endl;
		}
		cout << "Size: " << this->size[0] << "x" << this->size[1] << endl;
	}

	if (type == vectorType) {
		cout << "Vector" << endl;
		for (T k : this->matrix[0]) {
			cout << k << endl;
		}

		cout << "Size: " << this->size[1] << endl;
	}
	cout << "DataType: " << typeid(this->matrix[0][0]).name() << endl;
}

#endif /* MATRIX_H_ */
