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
	StackNode<T>* N = new StackNode<T>(d);	//Δημιουργία νέου κόμβου στοίβας που περιέχει το στοιχείο d
	if(!isEmpty()) N->next = top;			//Αν δεν έιναι κενή το επόμενοστοιχείο του γίνεται η τρέχουσα κορυφή της στοίβας
	top = N;								//Ο νέος κόμβος γίνεται η νέα κορυφή
}

template <class T>
T Stack<T>::pop()
{
	//Αν η στοίβα δεν είναι κενή
	if (!isEmpty()) {
		T d = top->data;
		top = top->next;	//Το επόμενο στοιχείο της κορυφής γίνεται η νέα κορυφή
		return d;			//Και επιστρέφεται το στοιχείο της
	}
}

template <class T>
bool Stack<T>::isEmpty()
{
	return !top;	//Επιστρέφει true αν η κορυφή είναι NULL
}