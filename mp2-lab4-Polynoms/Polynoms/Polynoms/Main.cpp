#include "stdafx.h"
#include <iostream>
#include "Polynoms.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	Polynom A, B, C;
	//Ввод
	A.Input();
	B.Input();
	//Первая сумма
	C = A + B;
	cout << "A=";
	A.Print();
	cout << "B=";
	B.Print();
	cout << "C=";
	C.Print();
	cout << endl;
	//Вторая сумма
	cout << "Cумма=";
	A.Plus(B);
	A.Print();
	cout << "B=";
	B.Print();
	return 0;
}