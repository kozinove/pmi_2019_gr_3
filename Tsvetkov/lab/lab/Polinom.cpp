#include "Polinom.h"

CList Polinom::getL() { return List; }
int Polinom::CalculPol(int x, int y, int z) { return List.calculCList(x, y, z); }
const Polinom Polinom::operator+(Polinom P) {
	CList H = P.getL();
	List = List + H;
	CListsort Res(List.getH());
	CList Q(Res.toList());
	
	Link* t = Q.getH()->next;
	while (t ->next!= Q.getH()) {
		if (t->res == t->next->res) {

			Link* tmp = t->next;
			t->a = t->a + t->next->a;
			
			t->next = tmp->next;

		}
		else t = t->next;
		
	}
	Polinom P1(Q);


	return P1;
}


const Polinom Polinom::operator-(Polinom P) {
	CList H = P.getL();
	List = List - H;
	CListsort Res(List.getH());
	CList Q(Res.toList());

	Link* t = Q.getH()->next;
	while (t->next != Q.getH()) {
		if (t->res == t->next->res) {

			Link* tmp = t->next;
			t->a = t->a + t->next->a;

			t->next = tmp->next;

		}
		else t = t->next;

	}
	Polinom P1(Q);


	return P1;
}