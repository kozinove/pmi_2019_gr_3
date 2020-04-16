#include "Navigator.h"

Navigator::Navigator(Node* root){
	{
		curr = root;
	}
}
void Navigator::addRirth(string v) {
	Node* a = new Node(v, curr->r, NULL);

	curr->r = a;
}
void Navigator::addLeft(string v) {
	Node* a = new Node(v, curr->l, NULL);

	curr->l = a;
}

void Navigator::deleteCurr() {

	if (st.CheckEmpty())return;
	Node* d = curr;
	up();
	if (curr->l == d) { curr->l = NULL; }
	if (curr->r == d) { curr->r = NULL; }
	deleteTree(d);
}
string& Navigator::val() {
	return curr->key;
}

bool Navigator::up() {
	if (st.CheckEmpty()) return false;
	curr = st.View_Top();
	st.Pop();
	return true;
}
bool Navigator::left() {
	if (curr->l == NULL) return false;
	st.Push(curr);
	curr = curr->l;
	return true;
}
bool Navigator::right() {
	if (curr->r == NULL) return false;
	st.Push(curr);
	curr = curr->r;
	return true;
}
Node* Navigator::getCurr() {
	return curr;
}