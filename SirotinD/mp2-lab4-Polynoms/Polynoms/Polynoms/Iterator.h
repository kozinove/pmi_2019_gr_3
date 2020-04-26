#pragma once


struct Monom {
	double Coef;
	double Deg;
	Monom *next;
};


class Iterator {
public:
	virtual bool hasNext() = 0;
	virtual Monom Next() = 0;
};
