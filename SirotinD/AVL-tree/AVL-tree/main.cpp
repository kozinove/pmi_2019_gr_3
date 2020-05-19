#include <stdio.h>
#include "Stack.h"
#include <iostream>
#include "Node.h"

using namespace std;


void print(Node * curr)
{
	if (curr == NULL) return;
	cout << curr->key;
	print(curr->l);
	print(curr->r);
}


void AVLadd(Node * _root, int _key) {
	Node * N = new Node(_key);
	if (_root = NULL) {
		_root = N;
		return;
	}
	Node * t = _root;
	while (t != NULL) {
		if (_key > t->key) {
			if (t->r != NULL) {
				t = t->r;
				continue;
			}
			else {
				t->r = N;
				return;
			}
		}
		else if (_key < t->key) {
			if (t->l != NULL) {
				t = t->l;
				continue;
			}
			else {
				t->l = N;
				return;
			}
		}
		else throw - 1;
	}
}

Node* AVLsrc(Node * root, int _key)
{
	Node * t = root;
	while (t != NULL)
	{
		if (_key > t->key)
		{
			if (t->r != NULL) t = t->r;
			else throw - 1;
		}
		else if (_key < t->key)
		{
			if (t->l != NULL) t = t->l;
			else throw - 1;
		}
		else return t;
	}
}



void AVLdel(Node * root, int _key) {
	Node * d = AVLsrc(root, _key);

	if ((d->l == NULL) && (d->r == NULL))
	{
		delete d;
	}
	else if ((d->l != NULL) && (d->r == NULL))
	{
		d = d->l;
	}
	else if ((d->l == NULL) && (d->r != NULL))
	{
		d = d->r;
	}
	else
	{
		Node * t = d->l;
		Node * temp = d;
		while (t->r != NULL)
		{
			temp = t;
			t = t->r;
		}
		int max = t->key;
		d->key = max;
		temp->r = t->l;
		t->l = NULL;
		delete t;
	}
}



int main() {
	Node* p1 = new Node(6);
	Node* p2 = new Node(1);
	Node* p3 = new Node(3);
	Node* p4 = new Node(2, NULL, p1);
	Node* p5 = new Node(4, p2, p4);
	Node* p6 = new Node(5, p5, p3);
	Node* root = p6;


	return 0;
}