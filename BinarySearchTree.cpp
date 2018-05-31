#include "stdafx.h"
#include "BinarySearchTree.h"

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(float b, float c)
{
	root = NULL;
	this->b = b;
	this->c = c;
}

template <class T>
void BinarySearchTree<T>::addNode(const T& data) {
	if (root == NULL) root = new Node<T>(data);
	else addNode(data, root);
}

template <class T>
void BinarySearchTree<T>::addNode(const T& data, Node<T>* curr) {
	if (data == curr->data) return;
	else if (data < curr->data) {
		if(curr->left == NULL) curr->left = new Node<T>(data);
		else addNode(data, curr->left);
	}
	else {
		if (curr->right == NULL) curr->right = new Node<T>(data);
		else addNode(data, curr->right);
	}
}

template <class T>
void BinarySearchTree<T>::preorder() {
	preorder(root);
}

template <class T>
void BinarySearchTree<T>::inorder() {
	inorder(root);
}

template <class T>
void BinarySearchTree<T>::postorder() {
	postorder(root);
}

template <class T>
void BinarySearchTree<T>::preorder(Node<T>* curr) {
	if (curr == NULL) return;
	cout << curr->data << " ";
	preorder(curr->left);
	preorder(curr->right);
}

template <class T>
void BinarySearchTree<T>::inorder(Node<T>* curr) {
	if (curr == NULL) return;
	inorder(curr->left);
	cout << curr->data << " ";
	inorder(curr->right);
}

template <class T>
void BinarySearchTree<T>::postorder(Node<T>* curr) {
	if (curr == NULL) return;
	postorder(curr->left);
	postorder(curr->right);
	cout << curr->data << " ";
}