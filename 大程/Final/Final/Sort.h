#pragma once
#ifndef _SORT_H_
#define _SORT_H_
#include "Function.h"
class Sort : public Function
{
	double *m;
	int mem;
	void merge(double*data, int a, int b, int length, int n);
public:
	Sort(){};
	Sort(double *a, int n);
	~Sort();
	void setmem(double *a, int n);
	void function();
};

#endif//_SORT_H_