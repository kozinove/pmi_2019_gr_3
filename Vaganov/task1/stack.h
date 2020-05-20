#pragma once
#include <iostream>
template <class Element>
class TStack {
protected:
	int Size;
	Element* pMem;
	int Top;		
public:
	TStack(int _size = 10);
	TStack(const TStack& op2);
	~TStack();
	void Push(Element elem);
	Element Pop();
	bool CheckEmpty();
	bool CheckFull();
	Element View_Top() const;
	Element GetSize() const;
};



template <class Element>
TStack<Element>::TStack(int _size) : Size(_size), Top(-1) {
	pMem = new Element[Size];
}
template <class Element>
TStack<Element>::TStack(const TStack& op2) : Size(op2.Size), Top(op2.Top) {
	pMem = new Element[Size];

	for (int i = 0; i < Top; i++)
		pMem[i] = op2.pMem[i];
}
template <class Element>
TStack<Element>::~TStack() {
	delete[] pMem;
	pMem = NULL;
}
template <class Element>
void TStack<Element>::Push(Element elem) {
	pMem[++Top] = elem;
}
template <class Element>
Element TStack<Element>::Pop() {
	return pMem[Top--];
}
template <class Element>
bool TStack<Element>::CheckEmpty() {
	return Top == -1 ? true : false;
}
template <class Element>
bool TStack<Element>::CheckFull() {
	return Top == (Size - 1) ? true : false;
}

template <class Element>
Element TStack<Element>::View_Top() const {
	return pMem[Top];
}
template <class Element>
Element TStack<Element>::GetSize() const {
	return Size;
}