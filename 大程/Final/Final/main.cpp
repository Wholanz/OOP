#include "stdafx.h"
using namespace std;
int main()
{
	for (;;)
	{
		try
		{
			system("cls");
			cout << "��ӭ��" << endl;
			Problem p;
			p.set();
			if (!p.getflag())
			{
				cout << "�ټ�" << endl;
				break;
			}
			p.solve();
			system("pause");
		}

		catch (...)
		{
			cout << "����δ֪������������������" << endl;
			break;
		}
	}
	
	return 0;
}