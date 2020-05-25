#pragma once
#include "stdafx.h"
#include <iostream>
class Monom;
using namespace std;
typedef Monom* Link;
class Monom {
	int deg;
	int cf;
	Link pointer;
public:
	Monom(int _deg=0, int _cf=0, Link _pointer=NULL)
	{
		deg = _deg;
		cf = _cf;
		pointer = _pointer;
	}
	void Setdeg(int _deg)
	{
		deg = _deg;
	}
	void SetCf(int _cf)
	{
		cf = _cf;
	}
	void SetPointer(Link _pointer)
	{
		pointer = _pointer;
	}
	int Getdeg() const
	{
		return deg;
	}
	int GetCf() const
	{
		return cf;
	}
	Monom* GetPointer() const
	{
		return pointer;
	}
};