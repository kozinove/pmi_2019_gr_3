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


	//example for enter polinom :x^2*y^3*z^4+2*x^2*y*z^3

	CList L;
	CList L2;
	string s;
	string s2;
	cin >> s;
	cin >> s2;
	Parser s1(s);
	Parser s3(s2);
	s1.showst();
	s3.showst();
	s1.toList(L);
	s3.toList(L2);
	L.showList();
	L2.showList();


	CListsort L1(L.getH());
	CListsort L3(L2.getH());
	CList res(L1.toList());
	CList res1(L3.toList());
	Polinom P(res);
	Polinom P1(res1);

	//P = P + P1;
	//CList List(P.getL());
	//List.showList();

	 int R = P.CalculPol(2, 2, 2);
	cout << R;

	return 0;

}