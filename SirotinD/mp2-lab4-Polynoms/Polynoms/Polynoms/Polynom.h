#pragma once
#include "Monom.h"
#include <string>
using namespace std;

class Polynom {
	Monom *h;
	Monom *l;
public:
	Polynom() {};

	void maxdeg(const string &str);
	void parser(const string &str); 
	void add(int _coef, int _deg); 
	void addS(int _coef, int _deg); 
	double calc(double a, double b, double c); 
	string printP(); 

	Polynom& operator=(const Polynom &Pn);
	Polynom operator+(const Polynom &Pn);
	Polynom operator-(const Polynom &Pn);
	Polynom operator*(const Polynom &Pn);

};