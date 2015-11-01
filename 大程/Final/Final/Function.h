#pragma once
#ifndef _Function_h_
#define _Function_h
class Function
{
	//int type;// 0是Matrix_Mul，1是Sort，2是Calculus，3是Equation
public:
	Function(){};
	virtual ~Function(){};
	virtual void function() = 0;
};
#endif //_Function_h_