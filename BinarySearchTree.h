#pragma once
#include "Node.h"
#include "Node.cpp"
#include <iostream>

using namespace std;

template <class T>
class BinarySearchTree
{
private:
	Node<T>* root;
	float b, c;
public:
	BinarySearchTree();
	BinarySearchTree(float b, float c);
	void addNode(const T& data);
	void addNode(const T& data, Node<T>* curr);
	void deleteNode(const T& data);
	void deleteNode(const T& data, Node<T>* curr);
	void deleteRoot();
	void Delete(Node<T>* parent, Node<T>* target);
	T subtreeMin(Node<T>* curr);
	bool search(const T& data);
	bool search(const T& data, Node<T>* curr);
	void rotateRight(Node<T>* curr);
	void rotateLeft(Node<T>* curr);
	void preorder();
	void preorder(Node<T>* r);
	void inorder();
	void inorder(Node<T>* r);
	void postorder();
	void postorder(Node<T>* r);
};

