#include "pch.h"
#include "polynom.h"

using namespace std;


polynom::polynom()
{
	head = new monom;
	last = new monom;
	head->next = head;
	last->next = head;
	last = head;
}

void polynom::parser(const string &s)
{
	int L = s.length();
	string temp;
	int xd = 0; int yd = 0; int zd = 0;
	int j = 0; int sign = 1; double coef = 0;
	int k = 0; int deg = 0;

	for (int i = 0; i < L; i++) {
		if ((s[i] == '-') || (s[i] == '+')) {
			if (s[i] == '-') sign = -1;
			else sign = 1;
		}

		if (k == 4) k = 0;
		j = 0;
		if (((s[i + j] >= '0') && (s[i + j] <= '9')) || (s[i + j] == '.')) {
			temp.clear();
			while (((s[i + j] >= '0') && (s[i + j] <= '9')) || (s[i + j] == '.')) {
				temp.push_back(s[i + j]);
				j++;
			}
			i += j;

			k++;
			switch (k) {
			case 1:
				coef = atof(temp.c_str());
				break;
			case 2:
				xd = atoi(temp.c_str());
				break;
			case 3:
				yd = atoi(temp.c_str());
			case 4:
				zd = atoi(temp.c_str());
			default:
				break;
			}
			if ((coef != 0) && (k == 4)) {
				deg = xd + yd * 10 + zd * 100;
				sortadd(sign*coef, deg);
			}
		}
	}
}

polynom& polynom::operator=(const polynom &P)
{
	if (this == &P) { return *this; }

	monom *temp = P.head->next;

	head->next = head;
	last = head;
	last->next = head;
	add(temp->c, temp->d);
	temp = P.head->next->next;

	while (temp != P.head) {
		this->sortadd(temp->c, temp->d);
		temp = temp->next;
	}
	return *this;
}

polynom polynom::operator+(const polynom &P)
{
	monom *temp1 = head->next;
	monom *temp2 = P.head->next;
	polynom *res = new polynom;

	while (temp1 != head && temp2 != P.head) {
		if (temp1->d < temp2->d) {
			if (temp1->c != 0) res->add(temp1->c, temp1->d);
			temp1 = temp1->next;
		}
		else if (temp1->d == temp2->d) {
			if (temp1->c + temp2->c != 0) res->add(temp1->c + temp2->c, temp1->d);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else {
			if (temp2->c != 0) res->add(temp2->c, temp2->d);
			temp2 = temp2->next;
		}
	}
	while (temp1 != head) {
		if (temp1->c != 0) res->add(temp1->c, temp1->d);
		temp1 = temp1->next;
	}
	while (temp2 != P.head) {
		if (temp2->c != 0) res->add(temp2->c, temp2->d);
		temp2 = temp2->next;
	}
	return *res;
}

polynom polynom::operator-(const polynom &P)
{
	polynom *res = new polynom;

	monom *temp = head;
	while (temp->next != head) {
		temp = temp->next;
		if (temp->c != 0) res->sortadd(temp->c, temp->d);
	}
	temp = P.head;
	while (temp->next != P.head) {
		temp = temp->next;
		if (temp->c != 0) res->sortadd((-1)*temp->c, temp->d);
	}
	return *res;
}

polynom polynom::operator*(const polynom &Pn)
{
	polynom *res = new polynom;
	monom *temp1 = head;
	while (temp1->next != head) {
		monom *temp2 = Pn.head;
		temp1 = temp1->next;
		while (temp2->next != Pn.head) {
			temp2 = temp2->next;
			if (temp2->c != 0) res->sortadd(temp1->c * temp2->c, temp1->d + temp2->d);
		}
	}
	return *res;
}

void polynom::add(int _c, int _d)
{
	if (_c != 0) {
		monom *T;
		T = new monom;

		T->c = _c;
		T->d = _d;
		T->next = head;

		last->next = T;
		last = T;
	}
}

void polynom::sortadd(int _c, int _d)
{
	monom *T;
	T = new monom;
	T->c = _c;
	T->d = _d;

	monom *temp = head;
	while ((temp->next->d < _d) && (temp->next != head)) {
		temp = temp->next;
	}
	if (temp->next->d == T->d) {
		if (temp->next->c + T->c != 0) {
			temp->next->c += T->c;
			delete T;
		}
		else {
			delete T;
			monom *d = new monom;
			d = temp->next;
			temp->next = temp->next->next;
			delete d;
		}
	}
	else {
		T->next = temp->next;
		temp->next = T;
	}
}

double polynom::calc(double x, double y, double z)
{
	int xd, yd, zd;
	monom* temp = head;
	double res = 0;
	while (temp->next != head) {
		temp = temp->next;
		int tdeg = temp->d;
		xd = tdeg % 10;
		tdeg = tdeg / 10;
		yd = tdeg % 10;
		tdeg = tdeg / 10;
		zd = tdeg % 10;
		res += (temp->c)*(pow(x, xd))*(pow(y, yd))*(pow(z, zd));
	}
	return res;
}


string polynom::out()
{
	int xd, yd, zd;

	int k = 0;
	string *s = new string;

	monom *temp = head->next;
	while (temp != head) {
		s->push_back(' ');
		if (k > 0) {
			if (temp->c > 0) s->push_back('+');
			else s->push_back('-');
		}
		else if ((temp->c) < 0) s->push_back('-');

		s->append(std::to_string(abs(temp->c)));

		int t = temp->d;
		xd = t % 10;
		t = t / 10;
		yd = t % 10;
		t = t / 10;
		zd = t % 10;

		s->push_back('x');
		s->append(std::to_string(xd));

		s->push_back('y');
		s->append(std::to_string(yd));

		s->push_back('z');
		s->append(std::to_string(zd));

		s->push_back(' ');
		temp = temp->next;
		k = 1;
	}

	return *s;
}