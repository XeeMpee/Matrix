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
using namespace std;

template<class T>
class Matrix {
public:
	Matrix();
	Matrix(vector<vector<T> > passMatrix);
	virtual ~Matrix();
private:
	vector<vector <T> >  matrix;
	int size[2];


public:
	void setMatrix(vector<vector<T> > passMatrix);
	T getMatrix();
	void printInfo();

};



//#  --------------------------------- DEFINICJE: ----------------------------------
//# Constructors, destructors:
template<class T>
inline Matrix<T>::Matrix(vector<vector<T> > passMatrix){
	this->size[0] = this->matrix.size();
	this->size[1] = this->matrix[0].size();
	this->matrix = passMatrix;
}

template<class T>
inline Matrix<T>::Matrix(){
	vector<vector <double > > vect = {{0,0,0},{0,0,0},{0,0,0}};
	this->matrix = vect;
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


//# Print info about matrix:
template<class T>
inline void Matrix<T>::printInfo(){

	cout << "Matrix:" << endl;
	for(vector <T> j : this->matrix){
		for(T k : j){
			cout << k << " ";
		}
	cout << endl;
	}

	cout << "Size: " << this->size[0] << "x" << this->size[1] << endl;
	cout << "Type: " << typeid(this->matrix[0][0]).name();
}

#endif /* MATRIX_H_ */
