#include"CList.h"
int step(int _x,int s){
	int i = 0; int q = 0;
	if (s == 1)return _x;
	q = 1;
	for (i = 0; i < s; i++) { 
		q = q*_x; }
	return q;
	
}
void CList::vstavka(Link* _t) //посмотреть в тетради
{

	
}
void CList::addF(int a,int x,int y ,int z) {

	Link* t = new Link;
	t = h;
	while (t->next != h) { t = t->next; }
	
	Link *T=new Link;
	T->a = a;
	T->z = z;
	T->x = x;
	T->y = y;
	T->res = x + y * 20 + z * 400;
	T->next = h;
	t->next = T;
	

}
void CList::showList() {
	Link* t = h;
	while (t->next != h) {
		t = t->next;
		cout << "a = " << t->a << " x = " << t->x << " y = " << t->y << " z = " << t->z << endl;

	}
}
void CList::index(Link* res) {

	Link* t = res, * t1 = h;
	while((t1->next!=h) &&(t->res <= t1->next->res)) {
		

		t1 = t1->next;
	}

	if (t->res == t1->next->res) {
		t1->next->a += t->a; return;
		
	}

	if (t->res > t1->res) {
		t->next = h;
		t1->next = t;
		return;

	}
	

	t->next = t1->next;
	t1->next = t;

	return;

}

int CList::calculCList(int x, int y, int z) {

	Link* t = h->next;
	int res = 0;

		while (t != h) {
			res += t->a * step(x, t->x) * step(y, t->y) * step(z, t->z);

			t = t->next;
		}
	
	return res;
}
const CList CList::operator+(CList P){
	Link* t = h->next;
	while (t != h) {
		P.index(t);

		t = t->next;
	}
	return P;
}
