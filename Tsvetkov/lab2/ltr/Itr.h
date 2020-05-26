#pragma once

#include "Node.h"
#include "stack.h"
class Itr {
	TStack <Node*> st;
public:
	Itr(Node* root);
	//TLR
	string nextF();
	//TRL
	string nextR();
	bool HasNext();
};