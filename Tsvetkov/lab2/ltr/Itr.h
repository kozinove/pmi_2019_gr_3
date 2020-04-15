#pragma once

#include "Node.h"
#include "stack.h"
class Itr {
	TStack <Node*> st;
public:
	Itr(Node* root) {
		st.Push(root);
	};
	//TLR
	int nextF() {
		Node* curr = st.View_Top();
		st.Pop();
		int val = curr->key;
		if (curr->r != NULL) st.Push(curr->r);
		if (curr->l != NULL) st.Push(curr->l);
		return val;
	};
	//TRL
	int nextR() {
		Node* curr = st.View_Top();
		st.Pop();
		int val = curr->key;
		if (curr->l != NULL) st.Push(curr->l);
		if (curr->r != NULL) st.Push(curr->r);
		return val;
	};
	bool HasNext() {
		return (!st.CheckEmpty());
	};
};