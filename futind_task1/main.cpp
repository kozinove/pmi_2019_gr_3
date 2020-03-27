#include <iostream>
#include "Node.h"
#include "stack.h"

//made by futind

using namespace std;

void RprintLTR(Node *curr) //recursive Left-Top-Right
{
	if (curr == NULL) return;
	RprintLTR(curr->l);
	cout << curr->key << ' ';
	RprintLTR(curr->r);
}

void RprintLRT(Node *curr) //recursive Left-Right-Top
{
	if (curr == NULL) return;
	RprintLRT(curr->l);
	RprintLRT(curr->r);
	cout << curr->key << ' ';
}

void IprintLTR(Node* root) //iterative Left-Top-Right 
{
	Stack<Node*> stack;
	while (root != NULL || !stack.isEmpty()) {
		if (!stack.isEmpty()) {
			root = stack.Pop();
			cout << root->key << ' ';
			if (root->r != NULL) root = root->r;
			else root = NULL;
		}
		while (root != NULL) {
			stack.Push(root);
			root = root->l;
		}
	}
}

int main()
{
	Node* p1 = new Node(6);
	Node* p2 = new Node(1);
	Node* p3 = new Node(3);
	Node* p4 = new Node(2,NULL,p1);
	Node* p5 = new Node(4,p2,p4);
	Node* p6 = new Node(5,p5,p3);

	Node* root = p6;

	RprintLRT(root);
	cout << endl;
	RprintLTR(root);
	cout << endl;
	IprintLTR(root);
	cout << endl;
	return 0;
}