#include "stdafx.h"
#include "Node.h"

template<class T>
Node<T>::Node()
{
	left = NULL;
	right = NULL;
}

template<class T>
Node<T>::Node(const T& d)
{
	data = d;	 
	left = NULL; 
	right = NULL;
}
