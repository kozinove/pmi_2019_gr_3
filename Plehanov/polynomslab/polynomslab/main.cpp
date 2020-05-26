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

	cout << "ËÀÁÎÐÀÒÎÐÍÀß ÐÀÁÎÒÀ ¹4" << endl;
	cout << "ÄËß ÏÐÎÄÎËÆÅÍÈß ÐÀÁÎÒÛ ÍÅÎÁÕÎÄÈÌÎ ÂÂÅÑÒÈ ÎÁÀ ÏÎËÈÍÎÌÀ Â ÏÎÄÎÁÍÎÌ ÔÎÐÌÀÒÅ: 1X1Y2Z3" << endl;
	cout << "ÌÀÊÑÈÌÀËÜÍÀß ÐÀÁÎ×Àß ÑÒÅÏÅÍÜ = 19" << endl;
	cout << "ÂÂÅÄÈÒÅ ÏÅÐÂÛÉ ÏÎËÈÍÎÌ: ";
	getline(cin, INPUT_S);
	FIRST.STRING_TO_POLYNOM(INPUT_S);
	cout << endl;
	cout << "ÂÂÅÄÈÒÅ ÂÒÎÐÎÉ ÏÎËÈÍÎÌ: ";
	getline(cin, INPUT_S);
	SECOND.STRING_TO_POLYNOM(INPUT_S);
	cout << endl;

	cout << "ÂÂÎÄ ÄÀÍÍÛÕ È ÂÛÏÎËÍÅÍÈÅ ÎÏÅÐÀÖÈÉ ÓÏÐÀÂËßÅÒÑß ÏÓÒ¨Ì ÂÂÎÄÀ ÖÈÔÐ" << endl;
	cout << "ÍÀÏÅ×ÀÒÀÉÒÅ 1 ×ÒÎÁÛ ÂÛÏÎËÍÈÒÜ ÑËÎÆÅÍÈÅ ÏÎËÈÍÎÌÎÂ" << endl;
	cout << "ÍÀÏÅ×ÀÒÀÉÒÅ 2 ×ÒÎÁÛ ÂÛÏÎËÍÈÒÜ ÂÛ×ÈÒÀÍÈÅ ÏÎËÈÍÎÌÎÂ" << endl;
	cout << "ÍÀÏÅ×ÀÒÀÉÒÅ 3 ×ÒÎÁÛ ÂÛÏÎËÍÈÒÜ ÓÌÍÎÆÅÍÈÅ ÏÎËÈÍÎÌÎÂ" << endl;
	cout << "ÍÀÏÅ×ÀÒÀÉÒÅ 4 ×ÒÎÁÛ ÂÛ×ÈÑËÈÒÜ ÇÍÀ×ÅÍÈÅ ÏÅÐÂÎÃÎ ÏÎËÈÍÎÌÀ Â ÒÎ×ÊÅ P(X,Y,Z)" << endl;
	cout << "ÍÀÏÅ×ÀÒÀÉÒÅ 4 ×ÒÎÁÛ ÂÛ×ÈÑËÈÒÜ ÇÍÀ×ÅÍÈÅ ÂÒÎÐÎÃÎ ÏÎËÈÍÎÌÀ Â ÒÎ×ÊÅ P(X,Y,Z)" << endl;
	cout << "ÍÀÏÅ×ÀÒÀÉÒÅ 0 ×ÒÎÁÛ ÂÛÉÒÈ" << endl;

	char c = ' ';
	while (c != '0') {
		cout << endl;
		cout << "ÂÀØÀ ÊÎÌÀÍÄÀ: ";
		cin >> c;
		switch (c) {
		case '1':
			RESULT = FIRST + SECOND;
			cout << "ÐÅÇÓËÜÒÀÒ : " << RESULT.OUT() << endl;
			break;
		case '2':
			RESULT = FIRST - SECOND;
			cout << "ÐÅÇÓËÜÒÀÒ : " << RESULT.OUT() << endl;			
			break;
		case '3':
			RESULT = FIRST * SECOND;
			cout << "ÐÅÇÓËÜÒÀÒ : " << RESULT.OUT() << endl;			
			break;
		case '4':
			cout << "ÂÂÅÄÈÒÅ ÒÎ×ÊÓ:\n";
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
			cout << "ÂÂÅÄÈÒÅ ÒÎ×ÊÓ:\n";
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