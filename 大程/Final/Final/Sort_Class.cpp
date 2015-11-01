#include "Sort.h"
#include <iostream>
using namespace std;
Sort::Sort(double *d, int i) 
{ 
	setmem(d, i);
}
Sort::~Sort()
{
	if (!m)
		delete[] m;
}
void Sort::setmem(double *d, int i)
{
	m = d;
	mem = i;
	function();
}
void Sort::function()
{
	int step = 1;
	for (;;)
	{
		std::cin.clear();
		std::cout << "请输入需要排序的数字数量：";
		std::cin >> mem;
		if (mem >= 1 && (std::ios::failbit && std::ios::badbit))
			break;
		else
			std::cout << "数字输入有误，请检查后重新输入" << std::endl;
	}
	m = new double[mem];
	for (;;)
	{
		std::cin.clear();
		std::cout << "请依次输入数字，以空格为分界" << std::endl;
		for (int i = 0; i < mem; i++)
			std::cin >> m[i];
		if ((std::ios::failbit && std::ios::badbit))
			break;
		else
			std::cout << "数字输入有误，请检查后重新输入" << std::endl;
	}
	while (step < mem)
	{
		for (int i = 0; i <= mem - step - 1; i += 2 * step)
			merge(m, i, i + step, step, mem);
		step = 2 * step;
	}
	cout << "结果是：" << endl;
	for (int i = 0; i < mem; i++)
		cout << m[i] << ' ';
	cout << endl;
}

void Sort::merge(double* data, int a, int b, int length, int n)
{
	int tmp;
	int i = 0;
	int j = 0;
	if (b + length - 1 >= n - 1)
		tmp = n - b;
	else
		tmp = length;
	double*d = new double[length + tmp];
	while (i < length  && j < tmp)
	{
		if (data[a + i] <= data[b + j])
		{
			d[i + j] = data[a + i];
			i++;
		}
		else
		{
			d[i + j] = data[b + j];
			j++;
		}
	}
	if (j == tmp)
	{
		memcpy(data + a + i + j, data + a + i, (length - i)*sizeof(double));
	}
	memcpy(data + a, d, (i + j)*sizeof(double));
}