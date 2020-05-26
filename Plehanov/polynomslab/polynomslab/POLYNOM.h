#pragma once

#include <string>
#include "MONOM.h"

using namespace std;

class POLYNOM {
	MONOM *h;
	MONOM *l;
public:
	POLYNOM();

	void STRING_TO_POLYNOM(const string &S); 
	void ADD(int _C, int _D); 
	void ADD_GREATER(int _C, int _D); 
	double CALCULATE_POLYNOM(double X, double Y, double Z); 
	string OUT(); 

	POLYNOM& operator=(const POLYNOM &P);
	POLYNOM operator+(const POLYNOM &P);
	POLYNOM operator-(const POLYNOM &P);
	POLYNOM operator*(const POLYNOM &P);

};