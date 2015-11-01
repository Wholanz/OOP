#include "stdafx.h"
using namespace std;
int main()
{
	for (;;)
	{
		try
		{
			system("cls");
			cout << "欢迎！" << endl;
			Problem p;
			p.set();
			if (!p.getflag())
			{
				cout << "再见" << endl;
				break;
			}
			p.solve();
			system("pause");
		}

		catch (...)
		{
			cout << "发生未知错误，请重新启动程序" << endl;
			break;
		}
	}
	
	return 0;
}