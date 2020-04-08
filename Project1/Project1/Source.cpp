#include <iostream>
using namespace std;
//рекурсивный вывод массива


void recursshow(int* a, int n) {
	if (n == 0)return;
	recursshow(a, n - 1);
	cout << a[n - 1] << ' ';

}

int main() {
	int* a;
	int n;
	cout << "enter size mas" << endl;
	cin >> n;
	a = new int[n];
	cout << "enter mas" << endl;
	for (int i = 0; i < n; i++) {

		cin >> a[i];
	}
	recursshow(a, n);


	return 0;
}