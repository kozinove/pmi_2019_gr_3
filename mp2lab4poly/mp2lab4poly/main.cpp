//#pragma comment(lib, "../MyLib.lib")
#include "polynom.h"
#include <iostream>

using namespace std;

void main() {
	//polynom *a = new polynom;
	//polynom *b = new polynom;
	//polynom *res = new polynom;

	polynom a;
	polynom b;
	polynom res;
	string s1;
	string s2;
	double x = 0; double y = 0; double z = 0;
	double r = 0;
	cout << "POLYNOMS" << endl;
	cout << "INPUT FORMAT: (Coef)x(x_deg)y(y_deg)z(z_deg)" << endl;
	cout << "BRACKETS ARE NOT NECCESSARY" << endl;
	cout << "INPUT POLYNOM A: ";
	getline(cin, s1);
	cout << "INPUT POLYNOM B: ";
	getline(cin, s2);
	a.parser(s1);
	b.parser(s2);
	cout << endl;
	char ch = ' ';
	cout << "TYPE 1 TO PERFORM A+B\n";
	cout << "TYPE 2 TO PERFORM A-B\n";
	cout << "TYPE 3 TO PERFORM A*B\n";
	cout << "TYPE 4 TO CALCULATE A\n";
	cout << "TYPE 5 TO CALCULATE B\n";
	cout << "TYPE 0 TO EXIT\n";
	while (ch != '0') {
		cin >> ch;
		switch (ch) {
		case '1':
			res = a + b;
			cout << "RESULT: " << res.ptos() << endl;
			break;
		case '2':
			res = a - b;
			cout << "RESULT: " << res.ptos() << endl;
			res.ptos();
			break;
		case '3':
			res = a * b;
			cout << "RESULT: " << res.ptos() << endl;
			res.ptos();
			break;
		case '4':
			cout << "INPUT A POINT:\n";
			cout << "	x = ";
			cin >> x;
			cout << endl;
			cout << "	y = ";
			cin >> y;
			cout << endl;
			cout << "	z = ";
			cin >> z;
			cout << endl;
			r = a.calc(x, y, z);
			cout << r;
			break;
		case '5':
			cout << "INPUT B POINT:\n";
			cout << "	x = ";
			cin >> x;
			cout << endl;
			cout << "	y = ";
			cin >> y;
			cout << endl;
			cout << "	z = ";
			cin >> z;
			cout << endl;
			r = b.calc(x, y, z);
			cout << r;
			break;
		case '0':
			return;
			break;
		default:
			break;
		}
	}
}