#pragma once

template <class T>
class Stack;

template <class T>
class StackNode
{
private:
	T data;	//�������� ��� ������
	StackNode* next;	//������� ���� ������� ������
public:
	StackNode();	//Default Constructor
	StackNode(T d);	//Constructor �� ������������ ��� ��������� ��� ������
	friend class Stack<T>;
};