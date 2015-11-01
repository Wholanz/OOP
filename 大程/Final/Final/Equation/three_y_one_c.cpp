#include "three_y_one_c.h"
#include "stdlib.h"
#include <iostream>
using namespace std;

void three_y_one_c::getCoeff()
{
    double ca1,cb1,cc1,cd1;
    double ca2,cb2,cc2,cd2;
    double ca3,cb3,cc3,cd3;

    cout<<"解三元一次方程组:" <<endl;
    cout<<"a1x+b1y+c1z+d1=0"<<endl;
    cout<<"a2x+b2y+c2z+d2=0"<<endl;
    cout<<"a1x+b1y+c3z+d3=0"<<endl;


    cout<<"请输入系数 a1, b1, c1, d1"<<endl;
    cout<<"a1="<<endl;
    cin>>ca1;
    cout<<"b1="<<endl;
    cin>>cb1;
    cout<<"c1="<<endl;
    cin>>cc1;
    cout<<"d1="<<endl;
    cin>>cd1;
    cout<<"请输入系数 a2, b2, c2, d2"<<endl;
    cout<<"a2="<<endl;
    cin>>ca2;
    cout<<"b2="<<endl;
    cin>>cb2;
    cout<<"c2="<<endl;
    cin>>cc2;
    cout<<"d2="<<endl;
    cin>>cd2;
    cout<<"请输入系数 a1, b1, c1, d1"<<endl;
    cout<<"a3="<<endl;
    cin>>ca3;
    cout<<"b3="<<endl;
    cin>>cb3;
    cout<<"c3="<<endl;
    cin>>cc3;
    cout<<"d3="<<endl;
    cin>>cd3;

    a1=ca1; b1=cb1; c1=cc1; d1=cd1;
    a2=ca2; b2=cb2; c2=cc2; d2=cd2;
    a3=ca3; b3=cb3; c3=cc3; d3=cd3;

}

double* three_y_one_c::solve()
{
    double d,e,f,g;
    double *x;

    x=(double*)malloc(sizeof(double) * 3);

    d = a1*b2*c3+b1*c2*a3+c1*a2*b3-c1*b2*a3-b1*a2*c3-a1*c2*b3;
    e = d1*b2*c3+b1*c2*d3+c1*d2*b3-c1*b2*d3-b1*d2*c3-d1*c2*b3;
    f = a1*d2*c3+d1*c2*a3+c1*a2*d3-c1*d2*a3-d1*a2*c3-a1*c2*d3;
    g = a1*b2*d3+b1*d2*a3+d1*a2*b3-d1*b2*a3-b1*a2*d3-a1*d2*b3;

    x[0]=e/d;  //这是利用克拉默法则求方程解的
    x[1]=f/d;
    x[2]=g/d;

    if(d==0)
        cout<<endl<<"有无数个解或无解"<<endl;

    else
    {
		num = 3;
		cout<<"x = "<<x[0]<<endl;
        cout<<"y = "<<x[1]<<endl;
        cout<<"z = "<<x[2]<<endl;

    }

    return x;



}











