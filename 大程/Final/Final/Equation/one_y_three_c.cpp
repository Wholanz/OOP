#include "one_y_three_c.h"
#include <iostream>
#include "math.h"
#include "stdlib.h"
using namespace std;

void one_y_three_c::getCoeff()
{
    double ca,cb,cc,cd;

    cout<<"解一元三次方程 ax^3+bx^3+cx+d=0"<<endl;
    cout<<"请输入系数 a, b, c, d"<<endl;
    cout<<"a="<<endl;
    cin>>ca;
    cout<<"b="<<endl;
    cin>>cb;
    cout<<"c="<<endl;
    cin>>cc;
    cout<<"d="<<endl;
    cin>>cd;

    a=ca;
    b=cb;
    c=cc;
    d=cd;
}


double* one_y_three_c::solve()
{
	num = 1;
	cout<<"请输入变量有效范围: x1~x2"<<endl;
    cout<<"x1="<<endl;
    cin>>x1;
    cout<<"x2="<<endl;
    cin>>x2;

    double f0,x0,f1,f2;

    f1=a*x1*x1*x1+b*x1*x1+c*x1+d;

    if(f1==0)
    {
        cout<<"x= "<<x1<<endl;
		return new double(x1);
    }

    f2=a*x2*x2*x2+b*x2*x2+c*x2+d;

    if(f2==0)
    {
        cout<<"x= "<<x2<<endl;
		return new double(x2);
    }

    do
    {
        x0=(x1+x2)/2;
        f0=a*x0*x0*x0+b*x0*x0+c*x0+d;

        if(f0==0) break;
        if(f0*f1<0)
        {
            x2=x0;
            f2=f0;
        }
        else
        {
            x1=x0;
            f1=f0;
        }

    }while(fabs(f0)>=0.0000001);

     cout<<"x= "<<x0<<endl;
	 return new double(x0);
}
