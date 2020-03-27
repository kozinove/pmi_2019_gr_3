#pragma once

struct Node
{
	int key;
	Node *l;
	Node *r;
	Node(int _key = 0, Node *_l = NULL, Node *_r = NULL) :key(_key), l(_l), r(_r) {}
};