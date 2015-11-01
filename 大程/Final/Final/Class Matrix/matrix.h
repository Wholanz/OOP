#ifndef _Matrix_H_
#define _Matrix_H_
#include <string>
#include <iostream>
class Matrix
{
    int line;//行数
    int row;//列数
    double *a;//存放元素
    bool IsDes;//析构标志
    //所有对元素的访问均从1起
public:
    Matrix(int l,int r = 1);
    Matrix();
    Matrix(const Matrix& a);
    ~Matrix();
    bool setm(int l,int  r);//设置矩阵大小
    bool set(int i,int j,double n);//设置矩阵元素
    double get(int i,int j)const;//获取矩阵元素
    bool print()const;//打印矩阵
    Matrix operator +(const Matrix& Matrix1)const;
    Matrix operator -(const Matrix& Matrix1)const;
    Matrix operator*(const double d);//数乘
    friend Matrix operator*(const double d, const Matrix c);//数乘
    //上面这一段是为了满足交换律
    friend Matrix operator/(const Matrix c,const double d);//数除
    Matrix operator *(const Matrix& m)const;//矩阵乘
    void operator =(const Matrix& m);//赋值运算
    void ChangeLine(const int a,const int b);//交换行
    void ChangeRow(const int a,const int b);//交换列
    std::ostream& operator<< (std::ostream& stream)const;//重载输出流
    std::istream& operator>> (std::istream& in);//重载输入流
    friend std::ostream& operator<< (std::ostream& stream, const Matrix other);//重载输出流
    friend std::istream& operator>> (std::istream& stream, Matrix other);//重载输入流，输入格式为先输入行数再输入列数，接下来输入矩阵
};
class NotMatch//不匹配错误类
{ 
public:
    std::string error;
    int al;//第一个矩阵的行数
    int ar;//列数
    int bl;//第二个矩阵行数
    int br;//列数
    NotMatch(std::string s, int a,int b,int c,int d)
    {
        error = s;
        al = a;
        ar = b;
        bl = c;
        br = d;
    }
    ~NotMatch(){};
};
class NotMatrix
{
public:
    int line;
    int row;
    NotMatrix(int l, int r)
    {
        line = l;
        row = r;
    }
    ~NotMatrix(){};
};
#endif//_Matrix.H_
/*
Following is throwed error

    catch(int &error)
    {
        switch (error)
        {
        case 0: cout << "No enough memory" << endl;
            break;
        case 1: cout << "out  of range" << endl;
            break;
        case 2: cout << "the value is already set" << endl;
            break;
        case 3:cout << "this two Matrix cannot add" << endl;
        default:cout << "unknow error" << endl;
            break;
        }
    }
    
    catch(NotMatch &e)
    {
        cout << e.error << endl;
        cout << "the first Matrix is " << e.al << "*" << e.ar << endl;
        cout << "the second Matrix is " << e.bl << "*" << e.br << endl;
    }
    catch(...)
    {
        cout << "Unknow error happened" << endl;
    }
*/