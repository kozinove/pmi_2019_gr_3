#pragma once
#include <iostream>
#include "stack.h"
#include "Node.h"
class Navigator {
	TStack <Node*> st;
	Node* curr;
public:
	Navigator(Node* root) {
		curr = root;
	}
	int value() {
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
};