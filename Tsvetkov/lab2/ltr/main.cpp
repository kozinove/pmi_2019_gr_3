#include <iostream>
#include "stack.h"
#include "Node.h"
#include "Itr.h"
#include "ItrLTR.h"
#include "ItrRTL.h"
#include "Navigator.h"
#include"Print.h"
using namespace std;
void deleteTree(Node* c) {

	if (c == NULL)return;
	deleteTree(c->l);
	deleteTree(c->r);
	delete c;
}

int main() {
	
	Node* p8 = new Node("abzac1.2");
	Node* p9 = new Node("text1.1.1");
	Node* p2 = new Node("abzac1.1",p8,p9);
	Node* p10 = new Node("text");
	Node* p3 = new Node("abzac2",NULL,p10);
	Node* p4 = new Node("abzac3");
	Node* p1 = new Node("glava2", NULL, p3);
	Node* p5 = new Node("glava1", p1, p2);
	Node* p6 = new Node("zagolovok", p5,NULL);
	Node* root = p6;

	
	
	
	//printfL(p6);
	//cout << "\n";
	//printItrL(p6);
	//Itr i1(root);
	//while (i1.HasNext()) {
	//	cout << i1.nextF() << " ";
	//};
	//cout << "\n";
	//printfR(p6);
	//cout << "\n";
	//printItrR(p6);
	//Itr i2(root);
	//while (i2.HasNext()) {
	//	cout << i2.nextR() << " ";
	//};
	//cout << "\n";
	//printLTR(p6);
	//cout << "\n";
	//printLTRItr(p6);
	//cout << "\n";
	//ItrLTR i3(root);
	//while (i3.HasNext()) {
	//	cout << i3.next() << " ";
	//}
	//cout << "\n";
	//printRTL(p6);
	//cout << "\n";
	//printRTLItr(p6);
	//cout << "\n";
	//ItrRTL i4(root);
	//while (i4.HasNext()) {
	//	cout << i4.next() << " ";
	//}
	//cout << "\n";
	Navigator n(root);
	bool f = true;
	while (true) {
		system("cls");
		cout << f << " " << n.val() << "\n";

		printTree(root, 0, n.getCurr());

		cout << endl;
		printf("1 up\n");
		printf("2 left\n");
		printf("3 right\n");
		printf("4 Edit\n");
		printf("5 add rigth\n");
		printf("6 add left\n");
		printf("7 delete current tree\n");
		int op;
		scanf("%d", &op);
		if (op == 1) f = n.up();
		if (op == 2) f = n.left();
		if (op == 3) f = n.right();
		if (op == 5) {

			cout << "enter string"<<endl;
			string v;
			cin >>v;
			n.addRirth(v);
		}
		if (op == 4) {

			cout << "enter val" << endl;
			cin >> n.val();
		}
		if (op == 6) {

			cout << "enter val" << endl;
			string v;
			cin >> v;
			n.addLeft(v);
		}
		if (op == 7) {
			n.deleteCurr();
		}
	}
	return 0;
}


//реализовать редактор текста с помощью дерева 
//сдать все дз 
//спросить все ли обходы реализовывать 
//редактирование текста ?