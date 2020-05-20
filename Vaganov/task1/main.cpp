#include <iostream>
#include "stack.h"
#include "Node.h"
#include "Itr.h"
#include "ItrLTR.h"
#include "ItrRTL.h"
#include "Navigator.h"
using namespace std;
// TLR
void printfL(Node* curr)                      
{
	if (curr == NULL) return;
	cout << curr->key<<" ";
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
			t=t->l;
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

int main() {
	Node* p1 = new Node(4);
	Node* p2 = new Node(6);
	Node* p3 = new Node(3);
	Node* p4 = new Node(5,NULL,p2);
	Node* p5 = new Node(2,p1,p4);
	Node* p6 = new Node(1,p5,p3);
	Node* root = p6;
	printfL(p6);
	cout << "\n";
	printItrL(p6);
	Itr i1(root);
	while (i1.HasNext()) {
		cout << i1.nextF() << " ";
	};
	cout << "\n";
	printfR(p6);
	cout << "\n";
	printItrR(p6);
	Itr i2(root);
	while (i2.HasNext()) {
		cout << i2.nextR() << " ";
	};
	cout << "\n";
	printLTR(p6);
	cout << "\n";
	printLTRItr(p6);
	cout << "\n";
	ItrLTR i3(root);
	while (i3.HasNext()) {
		cout << i3.next() << " ";
	}
	cout << "\n";
	printRTL(p6);
	cout << "\n";
	printRTLItr(p6);
	cout << "\n";
	ItrRTL i4(root);
	while (i4.HasNext()) {
		cout << i4.next() << " ";
	}
	cout << "\n";
	Navigator n(root);
	bool f = true;
	while (true) {
		cout<<f<<" "<<n.value()<<"\n";
		printf("1 up\n");
		printf("2 left\n");
		printf("3 right\n");
		int op;
		scanf("%d", &op);
		if (op == 1) f = n.up();
		if (op == 2) f = n.left();
		if (op == 3) f = n.right();
	}
	return 0;
}