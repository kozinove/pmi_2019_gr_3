#pragma once
#ifndef _POLINOM_H
#define _POLINOM_H
#include "CList.h"
class Polinom
{

	CList List;
public:
	Polinom(CList _L) { List = _L; }
	int CalculPol(int x, int y, int z);
	CList getL();
	const Polinom operator+(Polinom P);
	const Polinom operator-(Polinom P);
};
#endif