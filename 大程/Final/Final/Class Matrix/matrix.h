#ifndef _Matrix_H_
#define _Matrix_H_
#include <string>
#include <iostream>
class Matrix
{
    int line;//����
    int row;//����
    double *a;//���Ԫ��
    bool IsDes;//������־
    //���ж�Ԫ�صķ��ʾ���1��
public:
    Matrix(int l,int r = 1);
    Matrix();
    Matrix(const Matrix& a);
    ~Matrix();
    bool setm(int l,int  r);//���þ����С
    bool set(int i,int j,double n);//���þ���Ԫ��
    double get(int i,int j)const;//��ȡ����Ԫ��
    bool print()const;//��ӡ����
    Matrix operator +(const Matrix& Matrix1)const;
    Matrix operator -(const Matrix& Matrix1)const;
    Matrix operator*(const double d);//����
    friend Matrix operator*(const double d, const Matrix c);//����
    //������һ����Ϊ�����㽻����
    friend Matrix operator/(const Matrix c,const double d);//����
    Matrix operator *(const Matrix& m)const;//�����
    void operator =(const Matrix& m);//��ֵ����
    void ChangeLine(const int a,const int b);//������
    void ChangeRow(const int a,const int b);//������
    std::ostream& operator<< (std::ostream& stream)const;//���������
    std::istream& operator>> (std::istream& in);//����������
    friend std::ostream& operator<< (std::ostream& stream, const Matrix other);//���������
    friend std::istream& operator>> (std::istream& stream, Matrix other);//�����������������ʽΪ�����������������������������������
};
class NotMatch//��ƥ�������
{ 
public:
    std::string error;
    int al;//��һ�����������
    int ar;//����
    int bl;//�ڶ�����������
    int br;//����
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