#pragma once

template <class T>
class Stack;

template <class T>
class StackNode
{
private:
	T data;
	StackNode* next;
public:
	StackNode();
	StackNode(T d);
	friend class Stack<T>;
};