#pragma once
#include <iostream>


using namespace std;

template <class ValType>
struct Link {
	ValType val;
	Link<ValType> *next;
};

template <class ValType>
class Stack {
	Link<ValType> *h;
public:
	Stack() { h = NULL; }

	~Stack() {
		while (h != NULL) {
			this->Pop();
		}
	}

	bool isEmpty()
	{
		return(h == NULL);
	}

	void Push(ValType a)
	{
		Link<ValType> *T;
		T = new Link<ValType>;
		T->val = a;
		T->next = h;
		h = T;
	}

	ValType Pop()
	{
		if (isEmpty()) throw - 1;
		ValType a = h->val;
		Link<ValType> *T;
		T = h;
		h = h->next;
		delete T;
		return a;
	}

	ValType Top()
	{
		if (isEmpty()) throw - 1;
		return h->val;
	}

	void Show()
	{
		Link<ValType> *T = h;
		cout << '\n';
		while (T != NULL) {
			cout << (T->val) << ' ';
			T = T->next;
		}
	}
};
