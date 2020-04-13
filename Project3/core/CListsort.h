#pragma once
#include "CList.h"
#include <iostream>
using namespace std;
class CListsort {
	Link *L=new Link,*T;
public:
	CListsort(Link *h) {
		
		int n = 0;
		T = h->next;
		while (T != h) {
			n++;
			T = T->next;
		}
		int* a = new int[n];
		int* b = new int[n];
		T = h->next;
		int i = 0;
		while (T != h) {
			a[i] = T->res; b[i] = T->a;
			T = T->next;
			i++;
		}
		

		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (a[j] > a[j + 1]) {
					
					int temp = a[j]; int temp2 = b[j];
					a[j] = a[j + 1]; b[j] = b[j + 1];
					a[j + 1] = temp; b[j + 1] = temp2;
				}
			}
		}
		int t = n;
		 i = 0;
		 T = L;
		
		while (t > 0) {
			Link* q = new Link;
			q = L;
			while (q->next != L) {
				
				q = q->next; }

			Link* e = new Link;
	
			
			e->next = L;
			q->next = e;
			e->res = a[i];
			e->a = b[i];
			i++;
			t--;
			
		}
		

		T = L->next;
		while (T != L) {
			T->x = T->res % 20;
			int temp = T->res / 20;
			T->y = temp % 20;
			temp /= 20;
			T->z = temp % 20;
			T = T->next;
		}

	}
	void showList();
	Link* toList() { return L; }
};