#include"Itr.h"

Itr::Itr(Node* root) {
	st.Push(root);
};
//TLR
string Itr::nextF() {
	Node* curr = st.View_Top();
	st.Pop();
	string val = curr->key;
	if (curr->r != NULL) st.Push(curr->r);
	if (curr->l != NULL) st.Push(curr->l);
	return val;
};
//TRL
string Itr::nextR() {
	Node* curr = st.View_Top();
	st.Pop();
	string val = curr->key;
	if (curr->l != NULL) st.Push(curr->l);
	if (curr->r != NULL) st.Push(curr->r);
	return val;
};
bool Itr::HasNext() {
	return (!st.CheckEmpty());
};