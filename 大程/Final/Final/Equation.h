#pragma once
#ifndef _Equation_h_
#define _Equation_h_
#include "Function.h"
class Equation : public Function
{
public :
	Equation(){};
	virtual ~Equation(){};
	virtual void getCoeff() = 0;
	virtual double* solve() = 0;
	void function(){
		this->getCoeff();
		this->solve();
	}
	;
};
#endif //_Equation_h_