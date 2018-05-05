/*
 * MyException.h
 *
 *  Created on: 5 maj 2018
 *      Author: xeempee
 */

#ifndef MATRIXEXCEPTION_H_
#define MATRIXEXCEPTION_H_

#include <iostream>
#include <exception>
using namespace std;

class MatrixException : public exception {
public:
	MatrixException(string description) : description(description) {};
	virtual ~MatrixException(){};
private:
	string description;
public:
	void showDescription(){
		string underline(this->description.length(),  '-');
		cout << underline << endl;
		cout << this->description << endl;
	}
};

class MatrixSizeException : public MatrixException {

public:
	MatrixSizeException(string description) : MatrixException(description){};
};

#endif /* MATRIXEXCEPTION_H_ */
