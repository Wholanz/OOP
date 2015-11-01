#include <string>
#include "Matrix.h"
#include <iostream>
#include <sstream>
using namespace std;
Matrix::Matrix(int l,int r)
{
    a = new double[l * r];
    if(!a)
        throw 0;
    line = l;
    row = r;
    for(int i = 0;i < line * row ;i++)
    {
        a[i] = 0;
    }
}
Matrix::Matrix()
{
    line = row = -1;
}
Matrix::Matrix(const Matrix& c)
{
    line = c.line;
    row = c.row;
    if(line != -1 && row != -1)
    {
        a = new double[line * row];
        if(!a)
            throw 0;
        for(int i = 0;i < line * row ;i++)
        {
            a[i] = c.a[i];
        }
    }
}
Matrix::~Matrix()
{
    if(!IsDes)
    {
        delete [] a;
        IsDes = true;
    }
}
bool Matrix::setm(int l,int r)
{
    if(line != -1||row != -1)
        throw 2; 
    else
    {
        a = new double[l * r];
        line = l;
        row = r;
        for(int i = 0;i < line * row ;i++)
        {
            a[i] = 0;
        }
        return true;
    }
}
bool Matrix::set(int i,int j,double n)
{
    if(i > line||j > row)
    {
        throw(1);
        return false;
    }
    else
    {
        a[(i - 1) * row + j - 1] = n;
        return true;
    }
}
double Matrix::get(int i,int j)const
{
    if(i > line||j > row)
    {
        throw(1);
    }
    else 
        return a[(i - 1) * row + j - 1];
}
bool Matrix::print()const
{     
    for(int i = 1;i <= line * row ;i++)
    {
        cout << a[i - 1] << ' ';
        if(i != 0 && i % row == 0)
            cout << endl;
    }   
    cout << endl;
    return true;
}
Matrix Matrix::operator +(const Matrix& Matrix1)const
{
    int i, j;
    double temp;
    Matrix r(line, row);
    if(line != Matrix1.line || row != Matrix1.row)
        throw NotMatch("this tow Matrix cannot add or sub", line, row, Matrix1.line, Matrix1.row);
    for(i = 1;i <= line;i++)
        for(j = 1;j <= row;j++)
        {
            temp = get(i, j) + Matrix1.get(i, j);
            r.set(i, j, temp);
        }
    return r;
}
Matrix Matrix::operator -(const Matrix& Matrix1)const
{
    return (this->operator+  (Matrix1 * (-1)));
}
Matrix Matrix::operator *(double d)
{
    int i, j;
    double temp; 
    Matrix r(line,row);
    for(i = 1;i <= line;i++)
        for(j = 1;j <= row;j++)
        {
            temp = get(i, j) * d;
            r.set(i, j, temp);
        }
    return r;
}
Matrix operator *(double d,Matrix c)
{
    return c * d;
}
Matrix operator /(Matrix c, double d)
{
    return  (1.0 / d) * c;
}
Matrix Matrix::operator *(const Matrix& d)const
{
    int i, x, y;
    double temp;
    if(this->row != d.line)
        throw NotMatch("this tow Matrix cannot mul", line, row, d.line, d.row);
    Matrix r(this->row,d.line);
    for(x = 1;x <= r.line;x++)
        for(y = 1;y <= r.row;y++)
        {
            temp = 0;
            for(i = 1;i <= line;i++)
            {
                temp += get(i, x) * d.get(y, i);
            }
            r.set(x, y, temp);
        }
    return r;
}
void Matrix::ChangeLine(int a,int b)
{
    int i;
    double temp;
    for(i = 1;i <= row;i++)
    {
        temp = get(a, i);
        set(a, i, get(b, i));
        set(b, i, temp);
    }

}
void Matrix::ChangeRow(int a,int b)
{
    int i;
    double temp;
    for(i = 1;i <= line;i++)
    {
        temp = get(i, a);
        set(i, a, get(i, b));
        set(i, b, temp);
    }
}
void Matrix::operator =(const Matrix &other)
{
    line = other.line;
    row = other.row;
    a = new double[line * row];
    if(!a)
        throw 0;
    for(int i = 0;i < line * row ;i++)
    {
        a[i] = other.a[i];
    }
}
ostream& Matrix::operator<< (ostream& stream)const//重载输出流
{
    for(int i = 1;i <= line * row ;i++)
    {
        cout << a[i - 1] << ' ';
        if(i != 0 && i % row == 0)
            stream << endl;
    }   
    return stream;
}
istream& Matrix::operator>> (istream& in)//重载输入流
{
    int countl, countr;
    double m;
    char c = ' ';
    countl = countr = 0;
    row = -1;
    string line;
    istringstream is(line);
    while(getline(in,line))
    {
        countl++;
        countr = 0;
        while(c != '\n')
        {
            countr++;
            is >> m >> c;
            set(countl, countr, m);
        }
        if(row != -1 && countr != row)//不是第一次设置但是列数不一致
            throw NotMatrix(countl, countr);
        row = countr;
    }
    line = countl;
    return in;
}
std::ostream& operator<< (std::ostream& stream, const Matrix other)
{
    for(int i = 1;i <= other.line * other.row ;i++)
    {
        cout << other.a[i - 1] << ' ';
        if(i != 0 && i % other.row == 0)
            stream << endl;
    }   
    return stream;
}
std::istream& operator>> (std::istream& in, Matrix other)
{
    int count, lines, rows;
    double m;
    count = 0;
    in >> lines;
    in >> rows;
    other.setm(lines,rows);
    string line;
    istringstream is(line);
    while(getline(in,line))
    {
            count++;
            is >> m ;
            other.a[count] = m;
        if(count == rows * lines - 1)//不是第一次设置但是列数不一致
            break;
    }
    return in;
}