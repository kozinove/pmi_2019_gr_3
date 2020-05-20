#pragma once
#include <stdio.h>

struct Node
{
	int key;
	unsigned char height;
	Node* l;
	Node* r;
	Node(int k) { key = k; l = r = NULL; height = 1; }
};


unsigned char height(Node* p)
{
	return p ? p->height : 0;
}

int balancefactor(Node* p) //только ненулевые указатели
{
	return height(p->r) - height(p->l);
}

void fixheight(Node* p)
{
	unsigned char hl = height(p->l);
	unsigned char hr = height(p->r);
	p->height = (hl > hr ? hl : hr) + 1;
}

Node* rotateR(Node* p) // правый поворот вокруг p
{
	Node* q = p->l;
	p->l = q->r;
	q->r = p;
	fixheight(p);
	fixheight(q);
	return q;
}

Node* rotateL(Node* q) // левый поворот вокруг q
{
	Node* p = q->r;
	q->r = p->l;
	p->l = q;
	fixheight(q);
	fixheight(p);
	return p;
}


Node* balance(Node* p) // балансировка узла p
{
	fixheight(p);
	if (balancefactor(p) == 2)
	{
		if (balancefactor(p->r) < 0)
			p->r = rotateR(p->r);
		return rotateL(p);
	}
	if (balancefactor(p) == -2)
	{
		if (balancefactor(p->l) > 0)
			p->l = rotateL(p->l);
		return rotateR(p);
	}
	return p; 
}

Node* insert(Node* p, int k) 
{
	if (!p) return new Node(k);
	if (k < p->key)
		p->l = insert(p->l, k);
	else
		p->r = insert(p->r, k);
	return balance(p);
}