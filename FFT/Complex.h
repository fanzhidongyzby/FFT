#pragma once
#include<iostream>
using namespace std;
class Complex//a+b*i
{
	double a;//实数部分
	double b;//虚数部分
public:
	Complex(double a=0,double b=0);
	//+操作
	friend Complex operator +(Complex &x,Complex &y);
	friend Complex operator +(double x,Complex &y);
	friend Complex operator +(Complex &x,double y);
	//-操作
	friend Complex operator -(Complex &x,Complex &y);
	friend Complex operator -(double x,Complex &y);
	friend Complex operator -(Complex &x,double y);
	//*操作
	friend Complex operator *(Complex &x,Complex &y);
	friend Complex operator *(double x,Complex &y);
	friend Complex operator *(Complex &x,double y);
	//=操作
	Complex operator =(Complex &x);
	Complex operator =(double x);
	//<<操作
	friend ostream & operator<<(ostream&out,Complex&c);

	~Complex(void);
};

