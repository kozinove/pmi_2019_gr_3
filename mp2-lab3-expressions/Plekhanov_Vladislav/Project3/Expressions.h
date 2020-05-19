#pragma once
#ifndef _EXPRESSIONS_H
#define _EXPRESSIONS_H

#include <iostream>
#include <string> 
#include "TStack.h"

using namespace std;

class Expression {
private:
	string str;
	double Transform(string ourstr);

public:
	Expression(string _str);

	int Tabl(char chooooose);
	string ExpressionConvert(string str);
	double ExpressionCalc(string str);

};


#endif
