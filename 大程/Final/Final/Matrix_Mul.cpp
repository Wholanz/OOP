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
		const string s1("һ");
		const string s2("��");
		const string *s[2];
		s[0] = &s1;
		s[1] = &s2;
		Matrix result;
		i = 0;//���ڼ�¼�ǵڼ�������
		for (;;)
		{
			Matrix *m[2];
			m[0] = &m1;
			m[1] = &m2;
			flag = false;//��С�ı�־λ
			cout << "�������" << *s[i] << "������ĳ��Ϳ��ÿո�ָ������Իس�����" << endl;
			cin >> l >> r;
			if ((std::ios::failbit && std::ios::badbit) && (l >= 1 && r >= 1))
			{
				flag = true;
				m[i]->setm(l, r);
			}
			else
			{
				std::cout << "�������������������������" << std::endl;
				continue;
			}
			cout << "�����������" << *s[i] << "�������Ԫ�أ��ÿո�������Իس�����" << endl;
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
				std::cout << "�������������������������" << std::endl;
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
					cout << "������������ˣ����鲢��������" << endl;
					i = 0;
					continue;
				}
				break;
			}
		}
		cout << "�������ǣ�" << endl;
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