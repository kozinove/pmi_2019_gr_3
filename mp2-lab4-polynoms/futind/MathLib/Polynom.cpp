#include "pch.h"
#include <iostream>
#include "Polynom.h"

static int g_p = 0;

PolynomCList::PolynomCList()
{
	head = new Monom;
	head->next = head;
}

void PolynomCList::maxgp(const std::string &str)
{
	int j = 0;
	int L = str.length();
	int max = 0;
	std::string temp;

	for (int i = 0; i < L; i++) {
		if ((str[i] == 'x') || (str[i] == 'y') || (str[i] == 'z')) {
			j = 1;
			if (((str[i + j] >= '0') && (str[i + j] <= '9')) || (str[i + j] == '.')) {
				temp.clear();
				while (((str[i + j] >= '0') && (str[i + j] <= '9')) || (str[i + j] == '.')) {
					temp.push_back(str[i + j]);
					j++;
				}
				i += j - 1;
			}
			if (max < atoi(temp.c_str())) max = atoi(temp.c_str());
		}
	}
	if (g_p < 2 * max + 1) g_p = 2 * max + 1;
}

void PolynomCList::ffstr(const std::string &str)
{
	int L = str.length();
	std::string temp;
	int dx = 0;
	int dy = 0;
	int dz = 0;
	int j = 0; 
	int c = 1;
	double cxyz = 0;
	int k = 0;
	int max = 0;
	int deg = 0;

	for (int i = 0; i < L; i++) {
		if ((str[i] == '-') || (str[i] == '+')) {
			switch (str[i]) {
			case '-':
				c = -1;
				break;
			case '+':
				c = 1;
				break;
			default:
				break;
			}
		}
		if (k == 4) k = 0;
		j = 0;
		if (((str[i + j] >= '0') && (str[i + j] <= '9')) || (str[i + j] == '.')) {
			temp.clear();
			while (((str[i + j] >= '0') && (str[i + j] <= '9')) || (str[i + j] == '.')) {
				temp.push_back(str[i + j]);
				j++;
			}
			i += j;

			k++;
			switch (k) {
			case 1:
				cxyz = atof(temp.c_str());
				break;
			case 2:
				dx = atoi(temp.c_str());
				break;
			case 3:
				dy = atoi(temp.c_str());
			case 4:
				dz = atoi(temp.c_str());
			default:
				break;
			}
			if ((cxyz != 0) && (k == 4)) {
				deg = dx + dy * g_p + dz * g_p*g_p;
				addSorted(c*cxyz, deg);
			}
		}
	}
}

PolynomCList& PolynomCList::operator=(const PolynomCList &Pn)
{
	if (this == &Pn) { return *this; }
	Monom *temp = Pn.head->next;
	head->next = head;
	add(temp->Coef, temp->Deg);
	temp = Pn.head->next->next;
	while (temp != Pn.head) {
		this->addSorted(temp->Coef, temp->Deg);
		temp = temp->next;
	}
	return *this;
}

PolynomCList PolynomCList::operator+(const PolynomCList &Pn)
{
	Monom *temp = head;
	PolynomCList *res = new PolynomCList;
	while (temp->next != head) {
		temp = temp->next;
		res->addSorted(temp->Coef, temp->Deg);
	}
	temp = Pn.head;
	while (temp->next != Pn.head) {
		temp = temp->next;
		res->addSorted(temp->Coef, temp->Deg);
	}
	return *res;
}

PolynomCList PolynomCList::operator-(const PolynomCList &Pn)
{
	PolynomCList *res = new PolynomCList;
	PolynomCList mPn = Pn;
	Monom *temp = mPn.head;
	while (temp->next != mPn.head) {
		temp = temp->next;
		temp->Coef *= (-1);
	}
	temp = head;
	while (temp->next != head) {
		temp = temp->next;
		res->addSorted(temp->Coef, temp->Deg);
	}
	temp = mPn.head;
	while (temp->next != Pn.head) {
		temp = temp->next;
		res->addSorted(temp->Coef, temp->Deg);
	}
	return *res;
}

PolynomCList PolynomCList::operator*(const PolynomCList &Pn)
{
	PolynomCList *res = new PolynomCList;
	Monom *temp1 = head;
	while (temp1->next != head) {
		Monom *temp2 = Pn.head;
		temp1 = temp1->next;
		while (temp2->next != Pn.head) {
			temp2 = temp2->next;
			res->addSorted(temp1->Coef * temp2->Coef, temp1->Deg + temp2->Deg);
		}
	}
	return *res;
}

/*PolynomCList PolynomCList::operator/(const PolynomCList &Pn)
{
	PolynomCList *res = new PolynomCList;
	Monom *temp1 = head;
	while (temp1->next != head) {
		Monom *temp2 = Pn.head;
		temp1 = temp1->next;
		while (temp2->next != Pn.head) {
			temp2 = temp2->next;
			res->addSorted(temp1->Coef / temp2->Coef, temp1->Deg - temp2->Deg);
		}
	}
	return *res;
}*/

void PolynomCList::add(int _coef, int _deg)
{
	Monom *T;
	T = new Monom;
	T->Coef = _coef;
	T->Deg = _deg;
	T->next = head;
	
	Monom *temp = head;
	while (temp->next != head) {
		temp = temp->next;
	}

	temp->next = T;
}

void PolynomCList::addSorted(int _coef, int _deg)
{
	Monom *T;
	T = new Monom;
	T->Coef = _coef;
	T->Deg = _deg;
	
	Monom *temp = head;
	while ((temp->next->Deg < _deg) && (temp->next != head)) {
		temp = temp->next;
	}
	if (temp->next->Deg == T->Deg) {
		temp->next->Coef += T->Coef;
		delete T;
	}
	else {
		T->next = temp->next;
		temp->next = T;
	}
}

int sgn(double a) {
	if (a > 0) return 1;
	return -1;
}

std::string PolynomCList::ptos()
{
	int dx, dy, dz;
	int k = 0;
	std::string *s;
	s = new std::string;

	Monom *temp = head->next;
	while (temp != head) {
		s->push_back(' ');
		if (k > 0) {
			if ((sgn(temp->Coef) == 1)) s->push_back('+');
			else s->push_back('-');
		}
		else if (sgn(temp->Coef) == -1) s->push_back('-');

		s->append(std::to_string(abs(temp->Coef)));

		int tdeg = temp->Deg;
		dx = tdeg % g_p;
		tdeg = tdeg / g_p;
		dy = tdeg % g_p;
		tdeg = tdeg / g_p;
		dz = tdeg % g_p;

		s->push_back('x');
		s->append(std::to_string(dx));
		s->push_back('y');
		s->append(std::to_string(dy));
		s->push_back('z');
		s->append(std::to_string(dz));
		s->push_back(' ');

		temp = temp->next;
		k = 1;
	}

	return *s;
}

double PolynomCList::calculate(double x, double y, double z)
{
	int dx, dy, dz;
	Monom* temp = head;
	double res = 0;
	while (temp->next != head) {
		temp = temp->next;
		int tdeg = temp->Deg;
		dx = tdeg % g_p;
		tdeg = tdeg / g_p;
		dy = tdeg % g_p;
		tdeg = tdeg / g_p;
		dz = tdeg % g_p;
		res += (temp->Coef)*(pow(x, dx))*(pow(y, dy))*(pow(z, dz));
	}
	return res;
}


