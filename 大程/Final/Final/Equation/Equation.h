#ifndef _Equation_h_
#define _Equation_h_
#include "..\Function.h"
#include <iostream>
class Equation : public Function
{
	double *d;
protected:
	int num;
public :
	Equation()
	{ 
		d = NULL; 
		num = 0;
	};
	virtual ~Equation(){};
	virtual void getCoeff() = 0;
	virtual double* solve() = 0;
	void function()
	{
		getCoeff();
		d = solve();
	}
};
#endif //_Equation_h_