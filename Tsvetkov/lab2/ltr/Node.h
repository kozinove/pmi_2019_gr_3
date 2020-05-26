#pragma once
#include <string>
#include <iostream>
using namespace std;
struct Node {
	string key;
	Node* l;
	Node* r;
	Node(string _key = "", Node* _l = NULL, Node* _r = NULL) : key(_key), l(_l), r(_r) {}
};
