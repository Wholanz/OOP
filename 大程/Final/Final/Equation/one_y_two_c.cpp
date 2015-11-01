#include "one_y_two_c.h"
#include <iostream>
#include "math.h"
#include "stdlib.h"
using namespace std;

void one_y_two_c::getCoeff()
{
    double ca,cb,cc;
    cout<<"解一元二次方程 ax^2+bx+c=0"<<endl;
    cout<<"请输入系数 a, b, c"<<endl;
    cout<<"a="<<endl;
    cin>>ca;
    cout<<"b="<<endl;
    cin>>cb;
    cout<<"c="<<endl;
    cin>>cc;

    a=ca;
    b=cb;
    c=cc;
}


double* one_y_two_c::solve()
{
    cout<<endl;
	num = 2;
    if(b*b-4*a*c<0)   //当b*b-4*a*c<0时，解为虚根
	{
	    cout<<"x1=";
	    cout<<(b*-1)/(2*a)<<"+i*"<<sqrt(4*a*c-b*b)/(2*a)<<endl;
	    cout<<"x2=";
	    cout<<(b*-1)/(2*a)<<"-i*"<<sqrt(4*a*c-b*b)/(2*a)<<endl;

	    double *x;
	    x=(double*)malloc(sizeof(double) * 2);

	    x[0]=(b*-1)/(2*a);
	    x[1]=sqrt(4*a*c-b*b)/(2*a);

	    return x;


	}
	else
	{
		if((b*b-4*a*c)==0)    //若开根得到的是整数，有两个相等的根
		{
		    cout<<"x1=x2="<<endl;
		    cout<<((-b)/(2.0*a))<<endl;

		   double *x;
		   x=(double*)malloc(sizeof(double) * 1);
		   x[0]=(-b)/(2.0*a);

		   return x;




		}
		else  //若开根得到的不是整数，有两个不等的根
		{
		    cout<<"x1="<<endl;
			cout<<((-b+sqrt(b*b-4*a*c))/(2*a))<<endl;
			cout<<"x2="<<endl;
			cout<<((-b-sqrt(b*b-4*a*c))/(2*a))<<endl;

			 double *x;
	         x=(double*)malloc(sizeof(double) * 2);

	         x[0]=(b*-1)/(2*a);
	         x[1]=(-b+sqrt(b*b-4*a*c))/(2*a);

	         return x;
		}
	}

}
