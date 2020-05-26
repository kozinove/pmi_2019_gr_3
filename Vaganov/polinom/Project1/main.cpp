#include "polinom.h"
#include <iostream>
using namespace std;
void Maxst(string _s) {
	string s;
	int flag = 0, st = 0, j=0;
	for (int i = 0; i < _s.length(); i++) {
		j = 0;
		if (flag == 4) flag = 0;
		if ((_s[i] <= '9') && (_s[i] >= '0')) {
			s.clear();
			while ((_s[i + j] <= '9') && (_s[i + j] >= '0')) {
				s += _s[i+j];
				j++;
			}
			i += j;
			flag++;
			if (flag != 1) st = atoi(s.c_str());
			if (maxst < st) maxst = st;
		}
	}
}
int main() {
	Polinom p1;
	Polinom p2;
	Polinom res;
	string s1;
	string s2;
	int x, y, z;
	int r;
	int flag = 1;
	maxst = 0;
	cout << "Enter 1 polinom"<<"\n";
	cin >> s1;
	cout << "Enter 2 polinom" << "\n";
	cin >> s2;
	Maxst(s1);
	Maxst(s2);
	maxst = 2 * maxst;
	p1.parser(s1);
	p2.parser(s2);
	cout << "\n";
	while (flag != 0) {
		cout << "add polinom's - 1" << "\n";
		cout << "mult polinom's - 2" << "\n";
		cin >> flag;
		if (flag == 1) {
			flag = 0;
			p1.addpolinom(p2);
		}
		if (flag == 1) {
			flag = 0;
			p1.multpolinom(p2);
		}
	}
	p1.show;
	cout << "\n";
	cout << "enter x,y,z" << "\n";
	cout << "enter x" << "\n";
	cin >> x;
	cout << "enter y" << "\n";
	cin >> y;
	cout << "enter z" << "\n";
	cin >> z;
	r=p1.xyzpolinom(x, y, z);
	cout << "res=" << r;
	_getch();
	return 0;
}