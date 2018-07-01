#pragma once
#include "StackNode.h"
#include "StackNode.cpp"

template <class T>
class Stack
{
private:
	StackNode<T>* top;	//Το τελευταίο στοιχείο της στοίβας
public:
	Stack();	//Constructor
	void push(T item);	//Προσθήκη στην αρχή της στοίβας
	T pop();	//Διαγραφή και επιστροφή του τελευταίου στοιχείου της στοίβας
	bool isEmpty();	//Έλεγχος αν η στοίβα είναι κενή
};

