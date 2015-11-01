#pragma once
#ifndef _Matrix_Mul_h_
#define _Matrix_Mul_h_
#include "Function.h"
#include "Class Matrix\matrix.h"
class Matrix_Mul : public Function
{
	Matrix m1;
	Matrix m2;
public:
	Matrix_Mul() : m1(), m2(){};
	~Matrix_Mul(){};
	void function();
};
#endif //_Matrix_Mul_h_