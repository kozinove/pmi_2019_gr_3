#include "POLYNOM.h"
#include <iostream>

using namespace std;

POLYNOM::POLYNOM()
{
	h = new MONOM;
	l = new MONOM;
	h->N = h;
	l->N = h;
	l = h;
}

void POLYNOM::STRING_TO_POLYNOM(const string &S)
{
	int L = S.length();
	string temp;
	double COEF = 0; int DEG_X = 0; int DEG_Y = 0; int DEG_Z = 0;
	int j = 0; int k = 0;
	int sign = 1; 
	int DEG = 0;

	for (int i = 0; i < L; i++) {
		if ((S[i] == '-') || (S[i] == '+')) {
			switch (S[i]) {
			case '-':
				sign = -1;
				break;
			case '+':
				sign = 1;
				break;
			default:
				break;
			}
		}

		if (k == 4) k = 0;
		j = 0;
		if (((S[i + j] >= '0') && (S[i + j] <= '9')) || (S[i + j] == '.')) {
			temp.clear();
			while (((S[i + j] >= '0') && (S[i + j] <= '9')) || (S[i + j] == '.')) {
				temp.push_back(S[i + j]);
				j++;
			}
			i += j;

			k++;
			switch (k) {
			case 1:
				COEF = atof(temp.c_str());
				break;
			case 2:
				DEG_Y = atoi(temp.c_str());
				break;
			case 3:
				DEG_Y = atoi(temp.c_str());
			case 4:
				DEG_Z = atoi(temp.c_str());
			default:
				break;
			}
			if ((COEF != 0) && (k == 4)) {
				DEG = DEG_X + DEG_Y*20 + DEG_Z*20*20;
				ADD_GREATER(sign*COEF, DEG);
			}
		}
	}
}

void POLYNOM::ADD(int _C, int _D)
{
	if (_C != 0) {
		MONOM *T;
		T = new MONOM;
		T->C = _C;
		T->D = _D;
		T->N = h;
		l->N = T;
		l = T;
	}
}

void POLYNOM::ADD_GREATER(int _C, int _D)
{
	MONOM *T;
	T = new MONOM;
	T->C = _C;
	T->D = _D;
	MONOM *temp = h;
	while ((temp->N->D < _D) && (temp->N != h)) {
		temp = temp->N;
	}
	if (temp->N->D == T->D) {
		if (temp->N->C + T->C != 0) {
			temp->N->C += T->C;
			delete T;
		}
		else {
			delete T;
			MONOM *d = new MONOM;
			d = temp->N;
			temp->N = temp->N->N;
			delete d;
		}
	}
	else {
		T->N = temp->N;
		temp->N = T;
	}
}

double POLYNOM::CALCULATE_POLYNOM(double X, double Y, double Z)
{
	int DEG_X, DEG_Y, DEG_Z;
	MONOM* temp = h;
	double res = 0;
	while (temp->N != h) {
		temp = temp->N;
		int td = temp->D;
		DEG_X = td % 20;
		td = td / 20;
		DEG_Y = td % 20;
		td = td / 20;
		DEG_Z = td % 20;
		res += (temp->C)*(pow(X, DEG_X))*(pow(Y, DEG_Y))*(pow(Z, DEG_Z));
	}
	return res;
}

int SGN(double a) {
	if (a > 0) return 1;
	else if (a == 0) return 0;
	else return -1;
}

string POLYNOM::OUT()
{
	int DEG_X, DEG_Y, DEG_Z;
	int k = 0;
	string *s;
	s = new string;
	MONOM *temp = h->N;
	while (temp != h) {
		s->push_back(' ');
		if (k > 0) {
			if ((SGN(temp->C) == 1)) s->push_back('+');
			else s->push_back('-');
		}
		else if (SGN(temp->C) == -1) s->push_back('-');

		s->append(to_string(abs(temp->C)));

		int td = temp->D;
		DEG_X = td % 20;
		td = td / 20;
		DEG_Y = td % 20;
		td = td / 20;
		DEG_Z = td % 20;

		s->push_back('x');
		s->append(to_string(DEG_X));
		s->push_back('y');
		s->append(to_string(DEG_Y));
		s->push_back('z');
		s->append(to_string(DEG_Z));
		s->push_back(' ');

		temp = temp->N;
		k = 1;
	}
	return *s;
}

POLYNOM& POLYNOM::operator=(const POLYNOM &P)
{
	if (this == &P) { return *this; }
	MONOM *temp = P.h->N;
	h->N = h;
	l = h;
	l->N = h;
	ADD(temp->C, temp->D);
	temp = P.h->N->N;
	while (temp != P.h) {
		ADD_GREATER(temp->C, temp->D);
		temp = temp->N;
	}
	return *this;
}

POLYNOM POLYNOM::operator+(const POLYNOM &P)
{
	MONOM *temp1 = h->N;
	MONOM *temp2 = P.h->N;
	POLYNOM *res = new POLYNOM;
	while (temp1 != h && temp2 != P.h) {
		if (temp1->D < temp2->D) {
			if (temp1->C != 0) res->ADD(temp1->C, temp1->D);
			temp1 = temp1->N;
		}
		else if (temp1->D == temp2->D) {
			if (temp1->C + temp2->C != 0) res->ADD(temp1->C + temp2->C, temp1->D);
			temp1 = temp1->N;
			temp2 = temp2->N;
		}
		else {
			if (temp2->C != 0) res->ADD(temp2->C, temp2->D);
			temp2 = temp2->N;
		}
	}
	while (temp1 != h) {
		if (temp1->C != 0) res->ADD(temp1->C, temp1->D);
		temp1 = temp1->N;
	}
	while (temp2 != P.h) {
		if (temp2->C != 0) res->ADD(temp2->C, temp2->D);
		temp2 = temp2->N;
	}
	return *res;
}

POLYNOM POLYNOM::operator-(const POLYNOM &P)
{
	POLYNOM *res = new POLYNOM;
	MONOM *temp = h;
	while (temp->N != h) {
		temp = temp->N;
		if (temp->C != 0) res->ADD_GREATER(temp->C, temp->D);
	}
	temp = P.h;
	while (temp->N != P.h) {
		temp = temp->N;
		if (temp->C != 0) res->ADD_GREATER((-1)*temp->C, temp->D);
	}
	return *res;
}

POLYNOM POLYNOM::operator*(const POLYNOM &P)
{
	POLYNOM *res = new POLYNOM;
	MONOM *temp1 = h;
	while (temp1->N != h) {
		MONOM *temp2 = P.h;
		temp1 = temp1->N;
		while (temp2->N != P.h) {
			temp2 = temp2->N;
			if (temp2->C != 0) res->ADD_GREATER(temp1->C * temp2->C, temp1->D + temp2->D);
		}
	}
	return *res;
}