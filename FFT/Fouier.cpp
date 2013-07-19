#include "Fouier.h"
#include<iostream>
using namespace std;
#include<cmath>
#include<ctime>
#define DATALEN 32
#define KEYVALUE 10000 //生成随机浮点数的值，保证分子和分母在这个值之内
#define PI 3.14159265358979323846
Fouier::Fouier(void)
{
	data=new Complex[DATALEN];
	srand(unsigned int(time(0)));
	cout<<"源数据："<<endl;
	for(int i=0;i<DATALEN;i++)
	{
		data[i]=(rand()%(KEYVALUE))/(double)(rand()%(KEYVALUE)+1);
		if(i%5==0&&i!=0)
			cout<<endl;
		cout<<data[i]<<" ";
	}
	cout<<endl;
}


Fouier::~Fouier(void)
{
	delete [] data;
}
Complex Fouier:: W(int k,int n)//欧拉公式
{
	double alpha=-2*PI*k/n;
	return Complex(cos(alpha),sin(alpha));
}
void Fouier::fft(int start,int step,int len)
{
	if(len==1)//一个元素
	{
		//一个元素不需要变换
		return ;
	}
	fft(start,step*2,len/2);//X1(k)
	fft(start+step,step*2,len/2);//X2(k)
	Complex X1,X2;
	for(int i=0;i<len/2;i++)
	{
		X1=data[start+step*i*2];
		X2=data[start+step*(i*2+1)];
		//计算X(k):k=0~N/2-1
		data[start+step*i]=X1+W(i,len)*X2;
		//计算X(k):k=N/2~N-1
		data[start+step*(i+len/2)]=X1-W(i,len)*X2;
	}
}
void Fouier::fft()
{
	fft(0,1,DATALEN);
	cout<<"变换后数据："<<endl;
	for(int i=0;i<DATALEN;i++)
	{
		if(i%5==0&&i!=0)
			cout<<endl;
		cout<<data[i]<<" ";
	}
}