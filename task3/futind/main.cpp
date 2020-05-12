#include <iostream>
#include "Node.h"
#include "stack.h"

using namespace std;

void RTLprintR(Node *curr_t) {
	if (curr_t == NULL) return;
	RTLprintR(curr_t->r);
	cout << curr_t->key << " ";
	RTLprintR(curr_t->l);
}

void RTLprintI(Node *root) {
	Stack<Node*> st;
	Node *t = root;
	while (t != NULL) {
		st.Push(t);
		t = t->r;
	}

	while (!st.isEmpty()) {
		Node *curr_t = st.Top();
		st.Pop();
		cout << curr_t->key << " ";
		t = curr_t->l;
		while (t != NULL) {
			st.Push(t);
			t = t->r;
		}
	}
	
}

class RTLIterator {
	Stack<Node*> st;
public:
	RTLIterator(Node* root) {
		Node *t = root;
		while (t != NULL) {
			st.Push(t);
			t = t->r;
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
		Node * t = curr_t->l;
		while (t != NULL) {
			st.Push(t);
			t = t->r;
		}
		return key;
	}
 };

void Tadd(Node * _root, int _key) {
	Node * N = new Node(_key);
	if (_root = NULL) {
		_root = N;
		return;
	}
	Node * t = _root;
	while (t != NULL) {
		if (_key > t->key) {
			if (t->r != NULL) {
				t = t->r;
				continue;
			}
			else {
				t->r = N;
				return;
			}
		}
		else if (_key < t->key) {
			if (t->l != NULL) {
				t = t->l;
				continue;
			}
			else {
				t->l = N;
				return;
			}
		}
		else throw - 9; //Такой элемент уже есть в дереве
	}
}

Node* Tfind(Node * root,int _key) {
	Node * t = root;
	while (t != NULL) {
		if (_key > t->key) {
			if (t->r != NULL) t = t->r;
			else throw - 8; //Такого элемента в дереве не нашлось
		}
		else if (_key < t->key) {
			if (t->l != NULL) t = t->l;
			else throw - 8;
		}
		else return t;
	}
}



void Tdel(Node * root, int _key) {
	Node * Ntd = Tfind(root, _key);

	if ((Ntd->l == NULL) && (Ntd->r == NULL)) {
		delete Ntd;
	}
	else if ((Ntd->l != NULL) && (Ntd->r == NULL)) {
		Ntd = Ntd->l;
	}
	else if ((Ntd->l == NULL) && (Ntd->r != NULL)) {
		Ntd = Ntd->r;
	}
	else {
		Node * t = Ntd->l;
		Node * tm1 = Ntd;
		while (t->r != NULL) { //Ищем самый правый в левом поддереве
			tm1 = t;
			t = t->r;
		}
		int max = t->key;
		Ntd->key = max;
		tm1->r = t->l;
		t->l = NULL;
		delete t;
	}
}

int main() {
	Node * p1 = new Node(1);
	Node * p2 = new Node(5);
	Node * p3 = new Node(7);
	Node * p4 = new Node(4, NULL, p2);
	Node * p5 = new Node(2, p1, p4);
	Node * p6 = new Node(6, p5, p3);
	Node * root = p6;

	RTLprintR(root);
	cout << endl;
	RTLprintI(root);
	cout << endl;
	RTLIterator I(root);
	while (I.hasNext()) {
		cout << I.Next() << " ";
	}
	cout << endl;

	return 0;
}