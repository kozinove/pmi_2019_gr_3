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

	Link* t = h->next;
	while (t != h) {
		
		if((_t<=t->next)&&(_t>=t))

		t = t->next;
	}
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

int CList::calculCList(int x, int y, int z) {

	Link* t = h->next;
	int res = 0;

		while (t != h) {
			res += t->a * step(x, t->x) * step(y, t->y) * step(z, t->z);

			t = t->next;
		}
	
	return res;
}
