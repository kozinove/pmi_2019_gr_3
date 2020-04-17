#include"ItrLTR.h"


ItrLTR::ItrLTR(Node* root) {
	Node* t = root;
	while (t != NULL) {
		st.Push(t);
		t = t->l;
	}
};
bool ItrLTR::HasNext() {
	return (!st.CheckEmpty());
};
string ItrLTR::next() {
	string val;
	Node* curr_t = st.View_Top();
	st.Pop();
	val = curr_t->key;
	Node* t = curr_t->r;
	while (t != NULL) {
		st.Push(t);
		t = t->l;
	}
	return val;
}