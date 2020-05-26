#pragma once
#include "stdafx.h"
#include "Monom.h"
#include <iostream>
using namespace std;
class Polynom: public Monom {
	Link Head;
public:
	Polynom()
	{
		Head = new Monom(-1, 0, Head);
		Head->SetPointer(Head);
	}
	void Add(int deg, int cf)
	{
		Link prev = Head, cur=Head, tmp;
		if (cf != 0)
		{
			while ((cur->GetPointer()->Getdeg() != -1) && (cur->GetPointer()->Getdeg() > deg))
			{
				cur = cur->GetPointer();
			}
			cur = cur->GetPointer();
			while (prev->GetPointer() != cur)
				prev = prev->GetPointer();
			if (cur->Getdeg() == deg)
			{
				if ((cur->GetCf() + cf)!=0)
					cur->SetCf(cur->GetCf() + cf);
				else
				{
					prev->SetPointer(cur->GetPointer());
					cur->SetPointer(NULL);
					delete cur;
				}
			}
			else
			{
				tmp = new Monom(deg, cf, cur);
				prev->SetPointer(tmp);
			}
		}
	}
	//void Delete();
	void Print()
	{
		int x,y,z;
		Link tmp = Head->GetPointer();
		while (tmp->Getdeg() != -1)
		{
			x = tmp->Getdeg()/100;
			y = (tmp->Getdeg() % 100) / 10;
			z = tmp->Getdeg() % 10;
			if (tmp->GetPointer()->Getdeg() !=-1)
				if (tmp->GetPointer()->GetCf()>0)
					if (tmp->GetCf() != 1)
						cout << tmp->GetCf() <<"*"<< "x^" << x << "y^" << y << "z^" << z << "+";
					else 
						cout << "x^" << x << "y^" << y << "z^" << z << "+";
				else 
					cout << tmp->GetCf() << "*" << "x^" << x << "y^" << y << "z^" << z;
			else 
				cout << tmp->GetCf() << "*" << "x^" << x << "y^" << y << "z^" << z;
			tmp = tmp->GetPointer();
		}
		if (Head->GetPointer()->Getdeg() == -1)
		{
			cout << "0" << endl;
		}
		cout << endl;
	}

	Polynom& operator+(Polynom op2)
	{
		Polynom res;
		Link cur = res.Head->GetPointer(), point=Head->GetPointer();
		while (point->Getdeg() != -1)
		{
			res.Add(point->Getdeg(), point->GetCf());
			point = point->GetPointer();
		}
		point = op2.Head->GetPointer();
		while (point->Getdeg() != -1)
		{
			res.Add(point->Getdeg(), point->GetCf());
			point = point->GetPointer();
		}
		return res;
	}
	void Plus(Polynom op2)
	{
		Link cur1=Head->GetPointer(), cur2=op2.Head->GetPointer(), prev1=Head, prev2=op2.Head;
		while ((cur1->Getdeg() != -1) || (cur2->Getdeg() != -1))
		{
			if (cur1->Getdeg() > cur2->Getdeg())
			{
				cur1 = cur1->GetPointer();
				prev1 = prev1->GetPointer();
			}
			else
				if (cur1->Getdeg() == cur2->Getdeg())
				{
					if (cur1->GetCf() + cur2->GetCf() != 0)
					{
						cur1->SetCf(cur1->GetCf() + cur2->GetCf());
						prev2->SetPointer(cur2->GetPointer());
						cur2->SetPointer(NULL);
						cur2 = prev2->GetPointer();
					}
					else
					{
						prev1->SetPointer(cur1->GetPointer());
						cur1->SetPointer(NULL);
						delete cur1;
						cur1 = prev1->GetPointer();
						prev2->SetPointer(cur2->GetPointer());
						cur2->SetPointer(NULL);
						delete cur2;
						cur2 = prev2->GetPointer();
					}
				}
				else 
					if (cur1->Getdeg() < cur2->Getdeg())
					{
						prev1->SetPointer(cur2);
						prev2->SetPointer(cur2->GetPointer());
						cur2->SetPointer(cur1);
						cur2 = prev2->GetPointer();
						cur1 = prev1->GetPointer();
					}
		}
		if (cur1->Getdeg() == -1)
		{
			prev1->SetPointer(op2.Head->GetPointer());
			while (cur2->GetPointer()->Getdeg() != -1)
				cur2 = cur2->GetPointer();
			cur2->SetPointer(Head);
			op2.Head->SetPointer(op2.Head);
			}
			
	}
	void Input()
	{
		int x, y, z, cf ,c;
		do
		{
			cout << "Введите 4 числа: коэффициенты i степени" << endl;
			cin >> cf;
			do
				cin >> x;
			while ((x < 0) || (x > 9));
			do
				cin >> y;
			while ((y < 0) || (y > 9));
			do
				cin >> z;
			while ((z < 0) || (z > 9));
			Add(100 * x + 10 * y + z, cf);
			cout << "Ещё? Ввод 1 для продолжения, 0 - выход" << endl;
			cin >> c;
		} 
		while (c != 0);
	}
};
