#pragma once

template <class T>
class Stack;

template <class T>
class StackNode
{
private:
	T data;	//Στοιχείο του κόμβου
	StackNode* next;	//Δείκτης στον επόμενο κόμβος
public:
	StackNode();	//Default Constructor
	StackNode(T d);	//Constructor με αρχικοποίηση του στοιχείου του κόμβου
	friend class Stack<T>;
};