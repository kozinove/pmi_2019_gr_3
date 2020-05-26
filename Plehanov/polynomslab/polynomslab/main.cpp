#include "POLYNOM.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	string INPUT_S;
	POLYNOM FIRST;
	POLYNOM SECOND;
	POLYNOM RESULT;
	double X = 0; double Y = 0;	double Z = 0; double RES = 0;

	cout << "������������ ������ �4" << endl;
	cout << "��� ����������� ������ ���������� ������ ��� �������� � �������� �������: 1X1Y2Z3" << endl;
	cout << "������������ ������� ������� = 19" << endl;
	cout << "������� ������ �������: ";
	getline(cin, INPUT_S);
	FIRST.STRING_TO_POLYNOM(INPUT_S);
	cout << endl;
	cout << "������� ������ �������: ";
	getline(cin, INPUT_S);
	SECOND.STRING_TO_POLYNOM(INPUT_S);
	cout << endl;

	cout << "���� ������ � ���������� �������� ����������� ��Ҩ� ����� ����" << endl;
	cout << "����������� 1 ����� ��������� �������� ���������" << endl;
	cout << "����������� 2 ����� ��������� ��������� ���������" << endl;
	cout << "����������� 3 ����� ��������� ��������� ���������" << endl;
	cout << "����������� 4 ����� ��������� �������� ������� �������� � ����� P(X,Y,Z)" << endl;
	cout << "����������� 4 ����� ��������� �������� ������� �������� � ����� P(X,Y,Z)" << endl;
	cout << "����������� 0 ����� �����" << endl;

	char c = ' ';
	while (c != '0') {
		cout << endl;
		cout << "���� �������: ";
		cin >> c;
		switch (c) {
		case '1':
			RESULT = FIRST + SECOND;
			cout << "��������� : " << RESULT.OUT() << endl;
			break;
		case '2':
			RESULT = FIRST - SECOND;
			cout << "��������� : " << RESULT.OUT() << endl;			
			break;
		case '3':
			RESULT = FIRST * SECOND;
			cout << "��������� : " << RESULT.OUT() << endl;			
			break;
		case '4':
			cout << "������� �����:\n";
			cout << "X = ";
			cin >> X;
			cout << endl;
			cout << "Y = ";
			cin >> Y;
			cout << endl;
			cout << "Z = ";
			cin >> Z;
			cout << endl;
			RES = FIRST.CALCULATE_POLYNOM(X, Y, Z);
			cout << RES;
			break;
		case '5':
			cout << "������� �����:\n";
			cout << "X = ";
			cin >> X;
			cout << endl;
			cout << "Y = ";
			cin >> Y;
			cout << endl;
			cout << "Z = ";
			cin >> Z;
			cout << endl;
			RES = SECOND.CALCULATE_POLYNOM(X, Y, Z);
			cout << RES;
			break;
		case '0':
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}