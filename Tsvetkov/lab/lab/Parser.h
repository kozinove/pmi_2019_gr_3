#pragma once
#include<iostream>
#include"CList.h"
using namespace std;
class Parser {
	string* s;
	int Q = 0;
public:
	Parser(string _s) {
		int i = 0;
		int q = 0;
		int e = 0;
		while (_s[i] != '\0') {
			if (_s[i] == '+') q++;
			i++;
			e++;
		}

		s = new string[q + 1];
		Q = q + 1;
		for (int w = 0; w < q + 1; w++) {
			s[w] = "";
		}








		i = 0;
		int j = 0;
		while ((i < e) && (_s[i] != '\0')) {

			while ((_s[i] != '\0') && (_s[i] != '+')) {
				int g = 0;
				s[j] += _s[i];
				g++;
				i++;
			}
			i++;
			j++;

		}



	}
	void toList(CList L);


	void showst();





};
