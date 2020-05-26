#pragma once
#include <sstream>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include "monom.h"
using namespace std;
static int maxst;
class Polinom {
	monom* head;
	monom* t;
public:
	Polinom() {
		head = new monom;
		t = new monom;
		head->next = head;
		t->next = head;
		t = head;
	}
	void parser(string _s) {
		string s;
		int j = 0;
		int flag = 0;
		int d = 0;
		int l=1, k, stx, sty, stz;
		for (int i = 0; i < _s.length(); i++) {
			if (flag == 4) flag = 0;
			j = 0;
			if (_s[i] == '-') l = -1;			
			if ((_s[i] <= '9') && (_s[i] >= '0')) {
				s.clear();
				while ((_s[i + j] <= '9') && (_s[i + j] >= '0')) {
					s += _s[i+j];
					j++;
				}
				i += j;
				flag++;
				if (flag == 1) k = atoi(s.c_str());
				if (flag == 2) stx = atoi(s.c_str());
				if (flag == 3) sty = atoi(s.c_str());
				if (flag == 4) stz = atoi(s.c_str());
				if ((flag == 4) && (k != 0)) {
					d = stx + sty *(maxst) + (stz *(maxst)* (maxst));
					sortaddmonom(l * k, d);
				}
				if (_s[i] == '-') l = -1;
				if (_s[i] == '+') l = 1;
			}
		}
	}
	void sortaddmonom(int _k, int _d) {
		monom* T;
		T = new monom;
		T->k = _k;
		T->d = _d;
		monom* temp = head;
		while ((temp->next->d < _d) && (temp->next != head)) temp = temp->next;
		if (temp->next->d == T->d) {
			if (temp->next->k + T->k != 0) {
				temp->next->k += T->k;
				delete T;
			}
			else {
				delete T;
				monom* d = new monom;
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
	void show() {
		int stx, sty, stz;
		int flag = 0;
		monom* T = head->next;
		while (T != head) {
			cout<<' ';
			if (flag == 1) {
				if (T->k > 0) cout << '+';
			}
			int deg = T->d;
			cout<<T->k;
			stx = deg % maxst;
			cout << 'x';
			cout << stx;
			deg = deg / maxst;
			sty = deg % maxst;
			cout << 'y';
			cout << sty;
			deg = deg / maxst;
			stz = deg % maxst;
			cout<<'z';
			cout<< stz;
			T = T->next;
			flag = 1;
		}
	}
	int xyzpolinom(int _x, int _y, int _z){
		monom* T = head;
		int stx, sty, stz;
		int res = 0;
		while (T->next != head) {
			T = T->next;
			stx = T->d % maxst;
			T->d = T->d / maxst;
			sty = T->d % maxst;
			T->d = T->d / maxst;
			stz = T->d % maxst;
			res += (T->k) * (pow(_x, stx)) * (pow(_y,sty)) * (pow(_z, stz));
		}
		return res;
	}
	void addpolinom(Polinom p){
		monom* temp1 = head->next;
		monom* temp2 = p.head->next;
		while (temp1 != head && temp2 != p.head) {
			if (temp1->d < temp2->d) {
				if (temp1->k != 0) this->addmonom(temp1->k, temp1->d);
				temp1 = temp1->next;
			}
			else if (temp1->d == temp2->d) {
				if (temp1->k + temp2->k != 0) this->addmonom(temp1->k + temp2->k, temp1->d);
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			else {
				if (temp2->k != 0) this->addmonom(temp2->k, temp2->d);
				temp2 = temp2->next;
			}
		}
		while (temp1 != head) {
			if (temp1->k != 0) this->addmonom(temp1->k, temp1->d);
			temp1 = temp1->next;
		}
		while (temp2 != p.head) {
			if (temp2->k != 0) this->addmonom(temp2->k, temp2->d);
			temp2 = temp2->next;
		}
	}
	void addmonom(int _k, int _d){
		if (_k != 0) {
			monom* T;
			T = new monom;
			T->k = _k;
			T->d = _d;
			T->next = head;
			t->next = T;
			t = T;
		}
	}
	void multpolinom(Polinom p){
		monom* temp1 = head;
		while (temp1->next != head) {
			monom* temp2 = p.head;
			temp1 = temp1->next;
			while (temp2->next != p.head) {
				temp2 = temp2->next;
				if (temp2->k != 0) this->sortaddmonom(temp1->k * temp2->k, temp1->d + temp2->d);
			}
		}
	}
};