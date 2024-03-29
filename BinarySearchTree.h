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
	BinarySearchTree(float b, float c);  //Constructor �� ��������
	~BinarySearchTree();				//Destructor
	void addNode(const T& data);	   //�������� ������
	void addNode(const T& data, Node<T>* curr);	//�������� ������ (��������� ��������� �� pointer �� �����)
	int subtreeElements(Node<T>* subtreeRoot);	//������� ��������� ����������
	void deleteNode(const T& data);				//�������� ������
	void deleteNode(const T& data, Node<T>* curr);	//�������� ������ (��������� ��������� ��� ��� ������ ��� ��������� ���� �������� �� pointer �� �����)
	void Delete(Node<T>* parent, Node<T>* target);	//�������� ������ (��������� ��������� ���� �� ����� ���������� � �������� ��� ���������)
	T subtreeMin(Node<T>* curr);					//������ ��������� ��������� ����������
	Node<T>* reconstruct(Node<T>* r);				//����������� ����������
	void inorderToArray(Node<T>* r, Node<T>* arr[], int &index);	//���������� ����������� �� ������
	Node<T>* arrayToTree(Node<T>* arr[], int start, int end);		//��������� ������������� ������� ��� ������
	bool search(const T& data);					//����� ��� ��� ���� ������ ��� ��� ����
	bool search(const T& data, Node<T>* curr);	//��������� ���������
	void preorder();
	void preorder(Node<T>* r);	//���������
	void inorder();
	void inorder(Node<T>* r);	//�����������
	void postorder();
	void postorder(Node<T>* r);	//�����������
	bool isEmpty();				//������� �� �� ������ ����� �����
};

