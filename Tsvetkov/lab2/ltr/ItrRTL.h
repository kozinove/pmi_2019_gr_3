#pragma once
#include "stack.h"
#include "Node.h"
#include <iostream>
using namespace std;
class ItrRTL {
	TStack <Node*> st;
public:
	ItrRTL(Node* root);
	bool HasNext() ;
	string next();
};