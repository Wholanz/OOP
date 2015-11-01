#include "stdafx.h"
using namespace std;

Problem::Problem(int i){};
Problem::~Problem()
{
	if (flag)
		delete f;
}
bool Problem::getflag()
{
	return flag;
}
void Problem::set()
{
	
	flag = true;
	for (;;)
	{
		char type;
		cout << "请选择所需要的功能：" << endl;
		cout << "0、矩阵乘法计算" << endl;
		cout << "1、排序" << endl;
		cout << "2、积分计算" << endl;
		cout << "3、解方程" << endl;
		cout << "4、退出" << endl;
		cin >> type;
		switch (type)
		{
		case '0':f = new Matrix_Mul; break;
		case '1':f = new Sort; break;
		case '2':f = new Calculus; break;
		case '3':
			char t;
			for (;;)
			{
				cout << "请选择方程类型" << endl;
				cout << "0、一元一次" << endl;
				cout << "1、一元二次" << endl;
				cout << "2、一元三次" << endl;
				cout << "3、二元一次" << endl;
				cout << "4、三元一次" << endl;
				cin >> t;
				switch (t)
				{
				case '0':f = new one_y_one_c; break;
				case '1':f = new one_y_two_c; break;
				case '2':f = new one_y_three_c; break;
				case '3':f = new two_y_one_c; break;
				case '4':f = new three_y_one_c; break;
				default:cout << "输入不合法，请检查后重新输入" << endl; continue;
				}
				break;
			}break;
		case '4':flag = false; break;
		default:cout << "输入不合法，请检查后重新输入" << endl; continue;
		}
		break;
	}		
}
void Problem::solve()
{
	f -> function();
}
