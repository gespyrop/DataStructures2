#pragma once
#include "StackNode.h"
#include "StackNode.cpp"

template <class T>
class Stack
{
private:
	StackNode<T>* top;	//�� ��������� �������� ��� �������
public:
	Stack();	//Constructor
	void push(T item);	//�������� ���� ���� ��� �������
	T pop();	//�������� ��� ��������� ��� ���������� ��������� ��� �������
	bool isEmpty();	//������� �� � ������ ����� ����
};

