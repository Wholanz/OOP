#pragma once
#ifndef _Problem_H_
#define _Probllem_H_
#include <iostream>
#include "function.h"

class Problem
{
	Function *f;
	bool flag;//记录是否是退出，false为退出
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