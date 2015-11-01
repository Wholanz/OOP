#include "Matrix_Mul.h"
#include <iostream>
using namespace std;
void Matrix_Mul::function()
{
	int l, r, i, j, k;
	double n;
	bool flag = false;
	try
	{
		const string s1("一");
		const string s2("二");
		const string *s[2];
		s[0] = &s1;
		s[1] = &s2;
		Matrix result;
		i = 0;//用于记录是第几个矩阵
		for (;;)
		{
			Matrix *m[2];
			m[0] = &m1;
			m[1] = &m2;
			flag = false;//大小的标志位
			cout << "请输入第" << *s[i] << "个矩阵的长和宽，用空格分隔开，以回车结束" << endl;
			cin >> l >> r;
			if ((std::ios::failbit && std::ios::badbit) && (l >= 1 && r >= 1))
			{
				flag = true;
				m[i]->setm(l, r);
			}
			else
			{
				std::cout << "数字输入有误，请检查后重新输入" << std::endl;
				continue;
			}
			cout << "请依次输入第" << *s[i] << "个矩阵的元素，用空格隔开，以回车结束" << endl;
			if ((std::ios::failbit && std::ios::badbit) && flag)
			{
				for (j = 1; j <= l; j++)
				{
					for (k = 1; k <= r; k++)
					{
						cin >> n;
						m[i]->set(j, k, n);
					}
				}
			}
			else
			{
				std::cout << "数字输入有误，请检查后重新输入" << std::endl;
				continue;
			}
			i++;
			if (i >= 2)
			{
				try
				{
					result = m1 * m2;
				}
				catch (NotMatch)
				{
					cout << "两个矩阵不能相乘，请检查并重新输入" << endl;
					i = 0;
					continue;
				}
				break;
			}
		}
		cout << "计算结果是：" << endl;
		cout << result << endl;
	}
	catch (int &error)
	{
		switch (error)
		{
		case 0: cout << "No enough memory" << endl;
			break;
		case 1: cout << "out  of range" << endl;
			break;
		case 2: cout << "the value is already set" << endl;
			break;
		case 3:cout << "this two Matrix cannot add" << endl;
		default:cout << "unknow error" << endl;
			break;
		}
	}
}