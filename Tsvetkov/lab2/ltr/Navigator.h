#pragma once
#include <iostream>
#include "stack.h"
#include "Node.h"
void deleteTree(Node* c);
class Navigator {
	TStack <Node*> st;
	Node* curr;
public:
	Navigator(Node* root);
	void addRirth(string v);
	void addLeft(string v);
	void deleteCurr();
	string& val();
	bool up();
	bool left();
	bool right();
	Node* getCurr();
};