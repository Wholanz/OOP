#pragma once
#ifndef CALCULUS_H_
#define CALCULUS_H_
#include "Function.h"

struct stack{        //���ö�ջʵ�ֺ������ʽ�������ȼ�
	char func[100];  //ԭ�������ʽ�ַ���
	double output[50]; //���Դ洢���������
	char stack_out[10]; //���Դ洢��ջ�е������
	double Func_Calc(const double& x);

};


class Calculus : public Function{
private:
	const double high = 2000000000;  //���������
	const double low = -2000000000;  //���������
	const double distance = 0.0001;  //��ɢ��֮���x�����
	double x_from, x_to;   //���ֵ�x��Χ

	stack pre; //��ջ

	double Calc(double x); //����ĳ��xֵ�µĺ���ֵ����ĳ����ĺ���ֵ
	void GetFunction();    //��ȡ�������ʽ����Ҫ���룬�������x�ĺ����壬�м䲻���пո�ȷ���
	void GetRange();    //��ȡ���ַ�Χ
public:
	Calculus(double from = 0, double to = 1000){
		x_from = from;
		x_to = to;

	}

	double GetResult();
	void function();
};



#endif