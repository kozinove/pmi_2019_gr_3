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

int main() {
	Node * p1 = new Node(4);
	Node * p2 = new Node(6);
	Node * p3 = new Node(3);
	Node * p4 = new Node(5, NULL, p2);
	Node * p5 = new Node(2, p1, p4);
	Node * p6 = new Node(1, p5, p3);
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