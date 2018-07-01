#include "stdafx.h"
#include "StackNode.h"

template <class T>
StackNode<T>::StackNode()
{
	next = NULL;
}

template <class T>
StackNode<T>::StackNode(T d)
{
	data = d;	//Το στοιχείο του κόμβου παίρνει την τιμή του d
	next = NULL;
}
