#include "stdafx.h"
#include <iostream>
#include "Polynoms.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	Polynom A, B, C;
	//����
	A.Input();
	B.Input();
	//������ �����
	C = A + B;
	cout << "A=";
	A.Print();
	cout << "B=";
	B.Print();
	cout << "C=";
	C.Print();
	cout << endl;
	//������ �����
	cout << "C����=";
	A.Plus(B);
	A.Print();
	cout << "B=";
	B.Print();
	return 0;
}