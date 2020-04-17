#pragma once
// TLR

#include"Node.h"
#include"stack.h"
void printfL(Node* curr)
{
	if (curr == NULL) return;
	cout << curr->key << " ";
	printfL(curr->l);
	printfL(curr->r);
};
void printItrL(Node* root) {
	TStack <Node*> st;
	st.Push(root);
	while (!st.CheckEmpty()) {
		Node* curr = st.View_Top();
		st.Pop();
		cout << curr->key << " ";
		if (curr->r != NULL)
			st.Push(curr->r);
		if (curr->l != NULL)
			st.Push(curr->l);
	};
	cout << "\n";
};
// TRL
void printfR(Node* curr)
{
	if (curr == NULL) return;
	cout << curr->key << " ";
	printfR(curr->r);
	printfR(curr->l);
};
void printItrR(Node* root) {
	TStack <Node*> st;
	st.Push(root);
	while (!st.CheckEmpty()) {
		Node* curr = st.View_Top();
		st.Pop();
		cout << curr->key << " ";
		if (curr->l != NULL)
			st.Push(curr->l);
		if (curr->r != NULL)
			st.Push(curr->r);
	};
	cout << "\n";
}
// LTR
void printLTR(Node* curr_t) {
	if (curr_t == NULL) return;
	printLTR(curr_t->l);
	cout << curr_t->key << " ";
	printLTR(curr_t->r);
}
void printLTRItr(Node* root) {
	TStack<Node*> st;
	Node* t = root;
	while (t != NULL) {
		st.Push(t);
		t = t->l;
	}
	while (!st.CheckEmpty()) {
		Node* curr_t = st.View_Top();
		st.Pop();
		cout << curr_t->key << " ";
		t = curr_t->r;
		while (t != NULL) {
			st.Push(t);
			t = t->l;
		}
	}
}
// RTL
void printRTL(Node* curr_t) {
	if (curr_t == NULL) return;
	printRTL(curr_t->r);
	cout << curr_t->key << " ";
	printRTL(curr_t->l);
}
void printRTLItr(Node* root) {
	TStack<Node*> st;
	Node* t = root;
	while (t != NULL) {
		st.Push(t);
		t = t->r;
	}
	while (!st.CheckEmpty()) {
		Node* curr_t = st.View_Top();
		st.Pop();
		cout << curr_t->key << " ";
		t = curr_t->l;
		while (t != NULL) {
			st.Push(t);
			t = t->r;
		}
	}
}


void printTree(Node* c, int count_sp, Node* sel) {
	
	if (c == NULL)return;
	if (c == sel)cout <<"\n"<< "*";
	else cout << " " << endl;
	


	for (int i = 0; i < count_sp; i++) {
		cout << " ";
	}


	cout << c->key;//val
	printTree(c->r, count_sp + 1, sel);
	printTree(c->l, count_sp, sel);

}
