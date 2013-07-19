#pragma once
#include"Complex.h"
class Fouier
{
	Complex * data;
	void fft(int start,int step,int len);
	Complex W(int k,int n);//e^(-i*2*pi*k/n)
public:
	Fouier(void);
	~Fouier(void);
	
	void fft();
};

