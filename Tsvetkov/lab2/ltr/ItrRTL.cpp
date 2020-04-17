#include"ItrRTL.h"
#include "Node.h"

ItrRTL::ItrRTL(Node* root) {
		Node* t = root;
		while (t != NULL) {
			st.Push(t);
			t = t->r;
		}
	};
	bool  ItrRTL::HasNext() {
		return (!st.CheckEmpty());
	};
	string ItrRTL::next() {
		string val;
		Node* curr_t = st.View_Top();
		st.Pop();
		val = curr_t->key;
		Node* t = curr_t->l;
		while (t != NULL) {
			st.Push(t);
			t = t->r;
		}
		return val;
	}ItrRTL(Node* root) {
	Node* t = root;
	while (t != NULL) {
		st.Push(t);
		t = t->r;
	}
};
bool HasNext() {
	return (!st.CheckEmpty());
};
string next() {
	string val;
	Node* curr_t = st.View_Top();
	st.Pop();
	val = curr_t->key;
	Node* t = curr_t->l;
	while (t != NULL) {
		st.Push(t);
		t = t->r;
	}
	return val;
}