#include <stdio.h>
#include "Stack.h"
#include <iostream>

using namespace std;


struct Node
{
	int key;
	Node* l;
	Node* r;
	Node(int _key = 0, Node* _l = NULL, Node* _r = NULL) :key(_key), l(_l), r(_r) {}
};








void print(Node * curr)
{
	if (curr == NULL) return;
	//LTR
	cout << curr->key;
	print(curr->l);
	print(curr->r);
}

void printItr(Node* root)
{
	//LTR
	Stack<Node*> st;
	st.Push(root);
	while (!st.isEmpty())
	{
		Node* curr = st.Top();
		st.Pop();
		cout << curr->key << " ";
		if (curr->r != NULL)
		{
			st.Push(curr->r);
		}
		if (curr->l != NULL)
		{
			st.Push(curr->l);
		}
	}
	cout << "\n";
}

class LTRItr {
	Stack<Node*> st;
public:
	LTRItr (Node* root) {
		Node *t = root;
		while (t != NULL)
		{
			st.Push(t);
			t = t->l;
		}

	}

	bool hasNext() {
		return !st.isEmpty();
	}

	int Next() {
		int key;
		Node *curr_t = st.Top();
		st.Pop();
		key = curr_t->key;
		Node * t = curr_t->r;
		while (t != NULL) 
		{
			st.Push(t);
			t = t->l;
		}
		return key;
	}
};
//RTL

void RTLprint(Node *curr) {
	if (curr == NULL) return;
	//RTL
	cout << curr->key;
	RTLprint(curr->r);
	RTLprint(curr->l);
}

void RTLprintItr(Node *root) {
	Stack<Node*> st;
	st.Push(root);
	while (!st.isEmpty()) 
	{
		Node* curr = st.Top();
		st.Pop();
		cout << curr->key << " ";
		if (curr->l != NULL)
		{
			st.Push(curr->l);
		}
		if (curr->r != NULL)
		{
			st.Push(curr->r);
		}
	}


	cout << "\n";
}


class RTLItr {
	Stack<Node*> st;
public:
	RTLItr(Node* root) {
		Node *t = root;
		while (t != NULL) 
		{
			st.Push(t);
			t = t->r;
		}
	}

	bool hasNext() {
		return !st.isEmpty();
	}

	int next() {
		int key;
		Node *curr_t = st.Top();
		st.Pop();
		key = curr_t->key;
		Node * t = curr_t->l;
		while (t != NULL) 
		{
			st.Push(t);
			t = t->r;
		}
		return key;
	}
};

class Itr {
	Stack<Node*> st;
public:
	Itr(Node* root)
	{
		st.Push(root);
	}
	int next()
	{
		Node* curr = st.Top();
		st.Pop();
		int val = curr->key;
		if (curr->r != NULL)
		{
			st.Push(curr->r);
		}
		if (curr->l != NULL)
		{
			st.Push(curr->l);
		}
		return val;
	}
	bool hasNext() {
		return (st.isEmpty());
	}
};

int main() {
	Node* p1 = new Node(6);
	Node* p2 = new Node(1);
	Node* p3 = new Node(3);
	Node* p4 = new Node(2, NULL, p1);
	Node* p5 = new Node(4, p2, p4);
	Node* p6 = new Node(5, p5, p3);
	Node* root = p6;

	print(root);
	cout << "\n";
	printItr(root);

//	Itr i(root);
//	while (i.hasNext())
//	{
//		cout << i.next() << " ";
//	}

	cout << "\n";
	RTLprint(root);
	cout << "\n";
	RTLprintItr(root);

//	Itr I(root);
//	while (I.hasNext()) 
//	{
//		cout << I.next() << " ";
//	}

	return 0;
}