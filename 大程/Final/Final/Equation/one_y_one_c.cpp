#include "one_y_one_c.h"
#include <iostream>
using namespace std;


void one_y_one_c::getCoeff()
{
    double ca,cb;
    cout<<"��һԪһ�η��� ax+b=0"<<endl;
    cout<<"������ϵ�� a, b"<<endl;
    cout<<"a="<<endl;
    cin>>ca;
    cout<<"b="<<endl;
    cin>>cb;
    a=ca;
    b=cb;
}


double* one_y_one_c::solve()
{
	num = 1;
	cout<<endl;
    cout<<"x="<<(double)((-b)/a)<<endl;
    return (new double((-b)/a));
}
