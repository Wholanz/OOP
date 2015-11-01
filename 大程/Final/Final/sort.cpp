#include<string>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;
void mergesort(double *data, int n);
double* merge(double*data, int a, int b, int length, int n);

int main()
{
	vector<double>v;
	stringstream num;
	string input;
	double tmp;
	getline(cin, input);
	num.clear();
	num.str(input);
	while (1)
	{
		num >> tmp;
		if (num.fail())
			break;
		v.push_back(tmp);
	}
	double *a = new double[v.size()];
	for (int i = 0; i < v.size(); i++)
		a[i] = v[i];
	mergesort(a, v.size());
	for (int i = 0; i < v.size(); i++)
		cout << a[i] << " ";

}

void mergesort(double *data,int n)
{
	int step = 1;
	while (step < n)
	{
		for (int i = 0; i <= n - step - 1; i += 2 * step)
			merge(data, i, i + step, step, n);
		step = 2 * step;
	}
}

double* merge(double*data,int a, int b, int length, int n)
{
	int tmp;
	int i = 0;
	int j = 0;
	if (b + length - 1 >= n - 1)
		tmp = n - b;
	else
		tmp = length;
	double*d = new double[length + tmp];
	while (i < length  && j < tmp )
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
	return d;
}