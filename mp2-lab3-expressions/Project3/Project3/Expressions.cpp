#include <typeinfo>
#include <cassert>
#include "Expressions.h"

Expression::Expression(string _str)
{
	str = _str;
}

string Expression::ExpressionConvert(string str) {
	string	res = " ";
	int flag = 0;

	TStack<char> stack(10);

	if (str[0] == '-') {
		res =res + "0 ";
	}

	for (int i = 0; i < str.size(); i++) {
		//проверяем строку на наличие символов алфавита 
		if (isalpha(str[i])) {
			cout << "Введено НЕ выражение!" << endl;
			system("pause");
		}
		//исключают скобки и операции 
		if ((str[i] < 40 || str[i] > 43) && str[i] != '-' && str[i] != '/')
		{
			res = res + str[i];

			if (!((str[i + 1] != '+') && (str[i + 1] != '-') && (str[i + 1] != '/') && (str[i + 1] != '*') && (str[i + 1] != '(') && (str[i + 1] != ')'))) {
				res = res + ' ';
			}


		}
		else {
			flag = 1;
			//обрабоотка записи (-2)
			if (str[i] == '(' && str[i + 1] == '-') {
				res = res + "0 ";
			}

			if (str[i] == ')') {
				//смотрим что на вершине 
				while (stack.WhatIsTop() != '(') {
					res = res + stack.Pop();
				}
				stack.Pop();

			}
			else if (Tabl(str[i]) == 0 || Tabl(str[i]) > Tabl(stack.WhatIsTop()) || stack.CheckEmpty()) {
				stack.Push(str[i]);

			}
			else {
				int flazh = 1;
				char pop = stack.Pop();
				while (Tabl(str[i]) <= Tabl(pop))
				{
					res = res + pop;
					flazh = 0;

					if (!stack.CheckEmpty()) {
						pop = stack.Pop();
					}
					else
						break;
				}

				if (flazh) {
					stack.Push(flag);
				}

				stack.Push(str[i]);
			}
		}
	}

	while (!(stack.CheckEmpty())) {
		res = res + stack.Pop();
	}

	cout << "Польская запись: ";
	cout <<  res << endl;


	return res;
}



double Expression::ExpressionCalc(string str) {

	TStack<double> stack(str.size());

	double var1 = 0;
	double var2 = 0;

	string	ourline = " ";
	string tmp = " ";

	for (int i = 0; i < str.size(); i++) {

		if (((str[i] >= 0x30) && (str[i] <= 0x39)) || (str[i] == '.')) {
			tmp = tmp + str[i];
		}
		else {
			ourline = tmp;
			tmp.clear();

			if (ourline.length()) {
				stack.Push(Transform(ourline));

			}

		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*') {
			if (!(stack.CheckEmpty())) {
				var1 = stack.Pop();
				var2 = stack.Pop();
				if (str[i] == '*')
					stack.Push(var2 * var1);
				if (str[i] == '-')
					stack.Push(var2 - var1);
				if (str[i] == '+')
					stack.Push(var2 + var1);
				if (str[i] == '/')
					if (var1)
						stack.Push(var2 / var1);
					else
					{
						cout << "Деление на 0 " << endl;
						system("pause");
					}

			}
		}
	}

	return stack.Pop();
}

double Expression::Transform(string ourline) {
	int flagDouble = 0;
	int	flagMinus = 0;


	int	key = 0,
		key1 = 0,
		position = ourline.size() - 1;

	double res = 0.0;

	int amount = ourline.size();//размер строки

	for (int i = 0; i < amount; i++) {

		//проверка на знаки пунктуации в строке 
		if (ispunct(ourline[i]))
		{

			if (!(flagMinus) && (ourline[0] == '-'))
			{
				flagMinus = 1;
				key1 = 1;
			}
			//если нашли точку в строке
			if (ourline[i] == '.')
			{
				key= key+ 1;
				position = i;
				flagDouble = 1;
			}

		}
	}

	if (flagDouble>0) {

		double set = 1;
		double num1 = 0;
		double num2 = 0;

		for (int i = position + 1; i < amount; i++) {
			double number = ourline[i] - (int)'0';//Происходит тем самым преобразование к даблу
			set = set * 0.1;
			num1 = num1 * 10 + number;

		}

		for (int i = key1; i < position; i++) {
			double number = ourline[i] - (int)'0';//Происходит тем самым преобразование к даблу
			num2 = num2 * 10 + number;
		}

		if (flagMinus == 0)
			res = num2 + set * num1;
		else
			res = (-1) * (num2 + set * num1);
	}

	if (position == ourline.size() - 1) {
		for (int i = key1; i < ourline.size(); i++) {
			double tmp = ourline[i] - (int)'0';//Происходит тем самым преобразование к даблу
			res = res * 10 + tmp;
		}

		if (flagMinus)
			res = (-1) * res;
	}

	return res;
}

//Таблица приоритетов
int Expression::Tabl(char choice) {


	switch (choice) {
	case '(':
		return 0;
		break;

	case ')':
		return 1;
		break;

	case '+': case '-':
		return 2;
		break;

	case '*': case '/':
		return 3;
		break;
	}
}
