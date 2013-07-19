#include "Complex.h"

Complex::Complex(double a,double b)//Ðé²¿Ä¬ÈÏÊÇ0
{
	this->a=a;
	this->b=b;
}


Complex::~Complex(void)
{
}

Complex operator +(Complex &x,Complex &y)
{
	return Complex(x.a+y.a,x.b+y.b);
}
Complex operator +(double x,Complex &y)
{
	return Complex(x+y.a,y.b);
}
Complex operator +(Complex &x,double y)
{
	return Complex(x.a+y,x.b);
}

Complex operator -(Complex &x,Complex &y)
{
	return Complex(x.a-y.a,x.b-y.b);
}
Complex operator -(double x,Complex &y)
{
	return Complex(x-y.a,-y.b);
}
Complex operator -(Complex &x,double y)
{
	return Complex(x.a-y,x.b);
}

Complex operator *(Complex &x,Complex &y)
{
	return Complex(x.a*y.a-x.b*y.b,x.a*y.b+x.b*y.a);
}
Complex operator *(double x,Complex &y)
{
	return Complex(x*y.a,x*y.b);
}
Complex operator *(Complex &x,double y)
{
	return Complex(x.a*y,x.b*y);
}

Complex Complex::operator =(Complex &x)
{
	a=x.a;
	b=x.b;
	return *this;
}
Complex Complex::operator =(double x)
{
	a=x;
	b=0;
	return *this;
}
ostream & operator<<(ostream&out,Complex&c)
{
	if(c.a!=0||c.a==0&&c.b==0)
		out<<c.a;
	if(c.b!=0)
	{
		if(c.b>0)
			out<<"+";
		if(c.b!=1)
			out<<c.b;
		out<<"i";
	}
	return out;
}