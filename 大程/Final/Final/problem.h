#pragma once
#ifndef _Problem_H_
#define _Probllem_H_
#include <iostream>
#include "function.h"

class Problem
{
	Function *f;
	bool flag;//��¼�Ƿ����˳���falseΪ�˳�
public:
	Problem(){};
	Problem(int t);
	~Problem();
	void solve();
	void set();
	bool getflag();
};
class Happy{};

#endif //_Probllem_H_