#include "two_y_one_c.h"
#include "stdlib.h"
#include <iostream>
using namespace std;

void two_y_one_c::getCoeff()
{
    double ca1,cb1,cc1;
    double ca2,cb2,cc2;


    cout<<"解二元一次方程组:" <<endl;
    cout<<"a1x+b1y+c1=0"<<endl;
    cout<<"a2x+b2y+c2=0"<<endl;



    cout<<"请输入系数 a1, b1, c1"<<endl;
    cout<<"a1="<<endl;
    cin>>ca1;
    cout<<"b1="<<endl;
    cin>>cb1;
    cout<<"c1="<<endl;
    cin>>cc1;

    cout<<"请输入系数 a2, b2, c2"<<endl;
    cout<<"a2="<<endl;
    cin>>ca2;
    cout<<"b2="<<endl;
    cin>>cb2;
    cout<<"c2="<<endl;
    cin>>cc2;


    a1=ca1; b1=cb1; c1=cc1;
    a2=ca2; b2=cb2; c2=cc2;


}

double* two_y_one_c::solve()
{
    double d,e,f;
    double *x;

    x=(double*)malloc(sizeof(double) * 2);

    d=a1*b2-b1*a2;
    e=c1*b2-b1*c2;
    f=a1*c2-c1*a2;

    x[0]=e/d;
    x[1]=f/d;

    if(d==0)
        cout<<endl<<"有无数个解或无解"<<endl;

    else
    {
		num = 2;
        cout<<"x = "<<x[0]<<endl;
        cout<<"y = "<<x[1]<<endl;

    }

    return x;



}











