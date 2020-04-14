#include "CList.h"
#include<iostream>
#include"Parser.h"
#include"CListsort.h"
#include"Polinom.h"
using namespace std;
int main() {

	// CList a;
	// a.addF(2, 5, 1, 3);
	// a.addF(1, 1, 2, 3);
	// a.addF(5, 1, 10, 2);
	// a.showList();
	// CListsort b(a.getH());
	// CListsort b.showList();
	

	//x^2*y^3*z^4+2*x^2*y*z^3

	CList L;
	string s;
	cin >> s;
	Parser s1(s);
	s1.showst();
	s1.toList(L);
	L.showList();
	CListsort L1(L.getH());
	CList res(L1.toList());
	Polinom P(res);
	int R = P.CalculPol(2, 2, 2);
	cout << R;
	
	//с помощью итератора вывести полином
	//перегрузить операции для полинома
	return 0;

}