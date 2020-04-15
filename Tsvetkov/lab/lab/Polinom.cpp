#include "Polinom.h"

CList Polinom::getL() { return List; }
int Polinom::CalculPol(int x, int y, int z) { return List.calculCList(x, y, z); }
const Polinom Polinom::operator+(Polinom P) {
	CList H = P.getL();
	List = List + H;
	Polinom P1(List);
	return P1;
}
