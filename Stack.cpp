#include "stdafx.h"
#include "Stack.h"

template <class T>
Stack<T>::Stack()
{
	top = NULL;
}

template <class T>
void Stack<T>::push(T d)
{
	StackNode<T>* N = new StackNode<T>(d);
	if(!isEmpty()) N->next = top;
	top = N;
}

template <class T>
T Stack<T>::pop()
{
	if (!isEmpty()) {
		T d = top->data;
		top = top->next;
		return d;
	}
}

template <class T>
bool Stack<T>::isEmpty()
{
	if (top != NULL) return false;
	else return true;
}