﻿#pragma once

#include <iostream>
#include <string>

using namespace std;

struct TMonom
{
	double coef;
	int degree;
};
struct TLink
{
	TMonom monom;
	TLink *pNext;
	TLink()
	{
		monom.coef = 0;
		monom.degree = -1;
	}
};
class CPolynom
{
	TLink *pHead;
	void CreateHead()
	{
		pHead = new TLink;
		pHead->monom.coef = 0;
		pHead->monom.degree = -1;
	}
	string* arrStrMon;	// массив объявленных переменных
	size_t numMonom;	// количество мономов
	TMonom* arrMonom;	// массив мономов
	string* arrVar;		// массив объявленных переменных
	size_t numVar;		// количество переменных
public:
	static unsigned int Power;
	void ToArrVar(string strVar);		// перевод в массив объявленных переменных
	void ToArrStrMon(string strPol);	// перевод в массив строчных мономов

	CPolynom(string strPol, string strVar);
	~CPolynom();
	CPolynom();
	
	CPolynom operator + (const CPolynom &polynom);
	CPolynom operator * (double const c);
	string ToString(); 
	double Calculate();
};