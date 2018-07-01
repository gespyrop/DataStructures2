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
	data = d;	 //Το στοιχείο του κόμβου παίρνει την τιμή του d
	left = NULL; 
	right = NULL;
}
