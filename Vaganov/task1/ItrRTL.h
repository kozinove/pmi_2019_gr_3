#pragma once
#include "stack.h"
#include "Node.h"
#include <iostream>
using namespace std;
class ItrRTL {
	TStack <Node*> st;
public:
	ItrRTL(Node* root) {
		Node* t = root;
		while (t != NULL) {
			st.Push(t);
			t = t->r;
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
		Node* t = curr_t->l;
		while (t != NULL) {
			st.Push(t);
			t = t->r;
		}
		return val;
	}
};