#pragma once
#include"Link.h"
#include "iterator.h"
//#include"Polinom.h"
#include<iostream>
#include"CListsort.h"
using namespace std;
class CList {
	Link* h;
public:
	
	Iterator* getIterator() {
	
		//return new CListsort(h);//dopravit'
	}
	//int getVal() { return h->val; }
	Link* getH() { return h; }
	CList() {
		h = new Link;
	}

	void vstavka(Link* _t);
	//int GetValue() { return h->val; }

	CList(Link* _h) { h = _h; }

	void addF(int a,int x,int y,int z);
	void showList();
	
	int calculCList(int x,int y,int z);
};