#pragma once
#include "stack.h"
#include "Node.h"
#include <iostream>
using namespace std;
class ItrLTR {
	TStack <Node*> st;
public:
	ItrLTR(Node* root);
	bool HasNext();
	string next();
};