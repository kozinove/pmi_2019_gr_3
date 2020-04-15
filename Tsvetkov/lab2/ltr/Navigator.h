#pragma once
#include <iostream>
#include "stack.h"
#include "Node.h"
void deleteTree(Node* c);
class Navigator {
	TStack <Node*> st;
	Node* curr;
public:
	
	Navigator(Node* root) {
		curr = root;
	}

	void addRirth(int v) {
		Node* a = new Node(v,curr->r,NULL);

		curr->r = a;
	}
	void addLeft(int v) {
		Node* a = new Node(v, curr->l,NULL);

		curr->l = a;
	}

	void deleteCurr() {

		if (st.CheckEmpty())return;
		Node* d=curr;
		up();
		if (curr->l == d) { curr->l = NULL; }
		if (curr->r == d) { curr->r = NULL; }
		deleteTree(d);
	}
	int &value() {
		return curr->key;
	}

	bool up() {
		if (st.CheckEmpty()) return false;
		curr = st.View_Top();
		st.Pop();
		return true;
	}
	bool left() {
		if (curr->l == NULL) return false;
		st.Push(curr);
		curr = curr->l;
		return true;
	}
	bool right() {
		if (curr->r == NULL) return false;
		st.Push(curr);
		curr = curr->r;
		return true;
	}
	Node* getCurr() {
		return curr;
	}
};