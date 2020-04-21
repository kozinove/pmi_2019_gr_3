#pragma once

#include <string>
#include "Monom.h"

class PolynomCList {
	Monom *head;
public:
	PolynomCList();

	void maxgp(const std::string &str); //Находит максимальную степень в полиноме
	void ffstr(const std::string &str); //Парсер строки
	void add(int _coef, int _deg); //Добавление монома
	void addSorted(int _coef, int _deg); //Добавление монома по возрастанию
	double calculate(double x, double y, double z); //Вычисление полинома в точке пространства
	std::string ptos(); //Вывод полинома

	PolynomCList& operator=(const PolynomCList &Pn);
	PolynomCList operator+(const PolynomCList &Pn);
	PolynomCList operator-(const PolynomCList &Pn);
	PolynomCList operator*(const PolynomCList &Pn);
	//PolynomCList operator/(const PolynomCList &Pn);
	
};