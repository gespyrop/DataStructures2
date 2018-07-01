#pragma once
#include "Node.h"
#include "Node.cpp"
#include "Stack.h"
#include <iostream>
#include <math.h>

using namespace std;

template <class T>
class BinarySearchTree
{
private:
	Node<T>* root;
	int d, n;
	float b, c;
public:
	BinarySearchTree();					  //Default constructor
	BinarySearchTree(float b, float c);  //Constructor με ορίσματα
	~BinarySearchTree();				//Destructor
	void addNode(const T& data);	   //Προσθήκη κόμβου
	void addNode(const T& data, Node<T>* curr);	//Προσθήκη κόμβου (βοηθητική συνάρτηση με pointer σε κόμβο)
	int subtreeElements(Node<T>* subtreeRoot);	//Αριθμός στοιχείων υποδένδρου
	void deleteNode(const T& data);				//Διαγραφή κόμβου
	void deleteNode(const T& data, Node<T>* curr);	//Διαγραφή κόμβου (βοηθητική συνάρτηση για την εύρεση του στοιχείου προς διαγραφή με pointer σε κόμβο)
	void Delete(Node<T>* parent, Node<T>* target);	//Διαγραφή κόμβου (βοηθητική συνάρτηση ώστε να γίνει αναδρομικά η διαγραφή του στοιχείου)
	T subtreeMin(Node<T>* curr);					//Εύρεση ελαχίστου στοιχείου υποδένδρου
	Node<T>* reconstruct(Node<T>* r);				//Ανακτασκευή υποδένδρου
	void inorderToArray(Node<T>* r, Node<T>* arr[], int &index);	//Αποθήκευση προδιάταξης σε πίνακα
	Node<T>* arrayToTree(Node<T>* arr[], int start, int end);		//Κατασκευή ισορροπημένου δένδρου απο πίνακα
	bool search(const T& data);					//Καλεί την απο κάτω μέθοδο για την ρίζα
	bool search(const T& data, Node<T>* curr);	//Αναζήτηση στοιχείου
	void preorder();
	void preorder(Node<T>* r);	//Προδιάτξη
	void inorder();
	void inorder(Node<T>* r);	//Ενδοδιάταξη
	void postorder();
	void postorder(Node<T>* r);	//Μεταδιάταξη
	bool isEmpty();				//Έλεγχος αν το δένδρο είναι άδειο
};

