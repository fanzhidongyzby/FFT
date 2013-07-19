#pragma once
#include<iostream>
using namespace std;
class Complex//a+b*i
{
	double a;//ʵ������
	double b;//��������
public:
	Complex(double a=0,double b=0);
	//+����
	friend Complex operator +(Complex &x,Complex &y);
	friend Complex operator +(double x,Complex &y);
	friend Complex operator +(Complex &x,double y);
	//-����
	friend Complex operator -(Complex &x,Complex &y);
	friend Complex operator -(double x,Complex &y);
	friend Complex operator -(Complex &x,double y);
	//*����
	friend Complex operator *(Complex &x,Complex &y);
	friend Complex operator *(double x,Complex &y);
	friend Complex operator *(Complex &x,double y);
	//=����
	Complex operator =(Complex &x);
	Complex operator =(double x);
	//<<����
	friend ostream & operator<<(ostream&out,Complex&c);

	~Complex(void);
};

