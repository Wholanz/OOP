#pragma once
#ifndef _Function_h_
#define _Function_h
class Function
{
	//int type;// 0��Matrix_Mul��1��Sort��2��Calculus��3��Equation
public:
	Function(){};
	virtual ~Function(){};
	virtual void function() = 0;
};
#endif //_Function_h_