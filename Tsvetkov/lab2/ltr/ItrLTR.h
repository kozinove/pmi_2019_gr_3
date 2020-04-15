#pragma once
#include "stack.h"
#include "Node.h"
#include <iostream>
using namespace std;
class ItrLTR {
	TStack <Node*> st;
public:
	ItrLTR(Node* root) {
		Node* t = root;
		while (t != NULL) {
			st.Push(t);
			t = t->l;
		}
	};
	bool HasNext() {
		return (!st.CheckEmpty());
	};
	int next() {
		int val;
		Node* curr_t = st.View_Top();
		st.Pop();
		val = curr_t->key;
		Node* t = curr_t->r;
		while (t != NULL) {
			st.Push(t);
			t = t->l;
		}
		return val;
	}
};