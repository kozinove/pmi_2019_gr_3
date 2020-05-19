#pragma once
#ifndef _TSTACK_H
#define _TSTACK_H
#include <iostream>
using namespace std;

template <class Elem>
class  TStack {
	int Top;
	int Size;
	Elem *Pmem;
public:
	TStack(int _size = 0);
	TStack(const TStack &op2);
	~TStack();

	void Push(Elem el);
	Elem Pop();

	Elem WhatIsTop() const;//Смотрим что лежит в вершине 
	Elem GetSize() const;
	bool CheckEmpty();
	bool CheckFull();

};
#endif

template <class Elem>
TStack<Elem>::TStack(int _size) :Size(_size)
{
	Top = -1;
	Pmem = new Elem[Size];
}

template <class Elem>
TStack<Elem>::TStack(const TStack &op2) :Size(op2.Size), Top(op2.Top)
{
	Pmem = new Elem[Size];
	for (int i = 0; i < Top; i++)
		Pmem[i] = op2.Pmem[i];
}

template <class Elem>
void TStack<Elem>::Push(Elem el)
{
	Pmem[++Top] = el;
}

template <class Elem>
Elem TStack<Elem>::WhatIsTop() const
{
	return Pmem[Top];
}

template <class Elem>
Elem TStack<Elem>::GetSize() const
{
	return Size;
}

template <class Elem>
Elem TStack<Elem>::Pop()
{

	return Pmem[Top--];
}

template <class Elem>
bool TStack<Elem>::CheckEmpty()
{
	return Top == -1;
}
template <class Elem>

bool TStack<Elem>::CheckFull()
{
	return Top == (Size - 1);
}

template <class Elem>
TStack<Elem>::~TStack()
{
	delete[] Pmem;
	Pmem = NULL;
}

