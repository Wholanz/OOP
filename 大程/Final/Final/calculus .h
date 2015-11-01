#pragma once
#ifndef CALCULUS_H_
#define CALCULUS_H_
#include "Function.h"

struct stack{        //利用堆栈实现函数表达式运算优先级
	char func[100];  //原函数表达式字符串
	double output[50]; //用以存储输出的数字
	char stack_out[10]; //用以存储堆栈中的运算符
	double Func_Calc(const double& x);

};


class Calculus : public Function{
private:
	const double high = 2000000000;  //运算的上限
	const double low = -2000000000;  //运算的下限
	const double distance = 0.0001;  //离散点之间的x向距离
	double x_from, x_to;   //积分的x范围

	stack pre; //堆栈

	double Calc(double x); //计算某个x值下的函数值，即某个点的函数值
	void GetFunction();    //读取函数表达式，需要输入，输入关于x的函数体，中间不能有空格等符号
	void GetRange();    //读取积分范围
public:
	Calculus(double from = 0, double to = 1000){
		x_from = from;
		x_to = to;

	}

	double GetResult();
	void function();
};



#endif