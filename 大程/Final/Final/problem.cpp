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
		cout << "��ѡ������Ҫ�Ĺ��ܣ�" << endl;
		cout << "0������˷�����" << endl;
		cout << "1������" << endl;
		cout << "2�����ּ���" << endl;
		cout << "3���ⷽ��" << endl;
		cout << "4���˳�" << endl;
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
				cout << "��ѡ�񷽳�����" << endl;
				cout << "0��һԪһ��" << endl;
				cout << "1��һԪ����" << endl;
				cout << "2��һԪ����" << endl;
				cout << "3����Ԫһ��" << endl;
				cout << "4����Ԫһ��" << endl;
				cin >> t;
				switch (t)
				{
				case '0':f = new one_y_one_c; break;
				case '1':f = new one_y_two_c; break;
				case '2':f = new one_y_three_c; break;
				case '3':f = new two_y_one_c; break;
				case '4':f = new three_y_one_c; break;
				default:cout << "���벻�Ϸ����������������" << endl; continue;
				}
				break;
			}break;
		case '4':flag = false; break;
		default:cout << "���벻�Ϸ����������������" << endl; continue;
		}
		break;
	}		
}
void Problem::solve()
{
	f -> function();
}
