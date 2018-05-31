#pragma once
#include <iostream>

using namespace std;

template<class T>
class BinarySearchTree;

template <class T>
class Node
{
private:
	T data;
	Node<T>* left;
	Node<T>* right;

public:Node();
	Node(const T& d);

	friend class BinarySearchTree<T>;
};

