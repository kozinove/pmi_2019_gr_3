#pragma once
#include "pch.h"
#include <string>
#include <iostream>
#include "monom.h"

using namespace std;

class polynom {
	monom *head;
	monom *last;
public:
	polynom();
	polynom& operator=(const polynom &P);
	polynom operator+(const polynom &P);
	polynom operator-(const polynom &P);
	polynom operator*(const polynom &P);


	string out();
	void parser(const string &s); 
	void add(int _c, int _d); 
	void sortadd(int _c, int _d); 
	double calc(double x, double y, double z);

};