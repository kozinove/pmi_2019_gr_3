#include "CListsort.h"
#include<iostream>
using namespace std;
void CListsort::showList() {
	Link* t = L;
	while (t->next != L) {
		t = t->next;
		cout << "a = " << t->a << " x = " << t->x << " y = " << t->y << " z = " << t->z << endl;

	}
}