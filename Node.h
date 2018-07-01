#pragma once
#include <iostream>

using namespace std;

template<class T>
class BinarySearchTree;

template <class T>
class Node
{
private:
	T data;	//Στοιχείο του κόμβου
	Node<T>* left;	//Αριστερό παιδί
	Node<T>* right;	//Δεξί παιδί

public:
	Node();				//Default Constructor
	Node(const T& d);	//Constructor με αρχικοποίηση του στοιχείου του κόμβου

	friend class BinarySearchTree<T>;
};

