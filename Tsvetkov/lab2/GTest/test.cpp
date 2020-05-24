#include "pch.h"
#include "../ltr/Itr.h"
#include"../ltr/stack.h"
#include"../ltr/Node.h"
#include "../ltr/Navigator.h"
#include "../ltr/ItrLTR.h"
#include"../ltr/ItrRTL.h"
#include "../ltr/Print.h"
#include <string.h>

TEST(Itr, has_not_next) {
	string s="ff";
	Node* root = new Node(s, NULL, NULL);
	TStack<string> st;
	Itr i(root);
	EXPECT_EQ(i.HasNext(),false);
}

