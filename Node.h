#pragma once
#include <iostream>

using namespace std;

template<class T>
class BinarySearchTree;

template <class T>
class Node
{
private:
	T data;	//�������� ��� ������
	Node<T>* left;	//�������� �����
	Node<T>* right;	//���� �����

public:
	Node();				//Default Constructor
	Node(const T& d);	//Constructor �� ������������ ��� ��������� ��� ������

	friend class BinarySearchTree<T>;
};

