#pragma once
#include "Node.h"
#include "Stack.h"






class Navigator {
	Stack<Node*> st;
	Node* curr;
public:
	Navigator(Node * root) {
		curr = root;
	}

	int value() {
		return curr->key;
	}

	bool up() {
		if (st.isEmpty()) return false;
		curr = st.Top();
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
