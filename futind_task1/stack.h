#pragma once
#include <iostream>

template <class ValType>
struct Link {
	ValType Value;
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
		T->Value = a;
		T->next = h;
		h = T;
	}

	ValType Pop() 
	{
		if (isEmpty()) throw - 100;
		ValType a = h->Value;
		Link<ValType> *T;
		T = h;
		h = h->next;
		delete T;
		return a;
	}

	ValType Top()
	{
		if (isEmpty()) throw - 100;
		return h->Value;
	}

	void Show()
	{
		Link<ValType> *T = h;
		std::cout << '\n';
		while (T != NULL) {
			std::cout << (T->Value) << ' ';
			T = T->next;
		}
	}
};
