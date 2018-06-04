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
bool BinarySearchTree<T>::search(const T& data) {
	return search(data, root);
}

template <class T>
void BinarySearchTree<T>::deleteNode(const T& data) {
	deleteNode(data, root);
}

template <class T>
void BinarySearchTree<T>::deleteNode(const T& data, Node<T>* curr) {
	if (root != NULL) {
		if (data == root->data) {
			deleteRoot();
		}
		else {
			if (data < curr->data && curr->left != NULL) {
				if (data == curr->left->data) Delete(curr, curr->left);
				else deleteNode(data, curr->left);
			}
			else if (data > curr->data && curr->right != NULL) {
				if (data == curr->right->data) Delete(curr, curr->right);
				else deleteNode(data, curr->right);
			}
			else cout << "The tree doesn't contain " << data << "!" << endl;
		}
	}
	else return;
}

template <class T>
void BinarySearchTree<T>::deleteRoot() {
	if (root != NULL) {
		Node<T>* delPtr = root;
		int rootData = root->data;
		int rsm;

		if(root->left == NULL && root->right == NULL){
			root = NULL;
			delete delPtr;
		}
		else if (root->left == NULL && root->right != NULL) {
			root = root->right;
			delPtr->right = NULL;
			delete delPtr;
		}
		else if (root->left != NULL && root->right == NULL) {
			root = root->left;
			delPtr->left = NULL;
			delete delPtr;
		}
		else {
			rsm = subtreeMin(root->right);
			deleteNode(rsm);
			root->data = rsm;
		}
	}
	else return;
}

template <class T>
void BinarySearchTree<T>::Delete(Node<T>* parent, Node<T>* target) {
	Node<T>* delPtr;
	T targetData = target->data;
	int rsm;

	if (target->left == NULL && target->right == NULL) {
		delPtr = target;
		if (parent->left == target) parent->left = NULL;
		else parent->right = NULL;
		delete delPtr;
	}
	else if (target->left == NULL && target->right != NULL) {
		if (parent->left == target) parent->left = target->right;
		else parent->right = target->right;
		target->right = NULL;
		delPtr = target;
		delete delPtr;
	}
	else if (target->left != NULL && target->right == NULL) {
		if (parent->left == target) parent->left = target->left;
		else parent->right = target->left;
		target->left = NULL;
		delPtr = target;
		delete delPtr;
	}
	else {
		rsm = subtreeMin(target->right);
		deleteNode(rsm, target);
		target->data = rsm;
	}

}

template <class T>
T BinarySearchTree<T>::subtreeMin(Node<T>* curr) {
	while (curr->left != NULL) curr = curr->left;
	return curr->data;
}

template <class T>
bool BinarySearchTree<T>::search(const T& data, Node<T>* curr) {
	if (curr == NULL) return false;
	else if (data == curr->data) return true;
	else if (data < curr->data) return search(data, curr->left);
	else return search(data, curr->right);
}

template <class T>
void BinarySearchTree<T>::rotateRight(Node<T>* curr) {
	Node<T>* L = curr->left;
	if (curr == root) root = L;
	curr->left = L->right;
	L->right = curr;
}

template <class T>
void BinarySearchTree<T>::rotateLeft(Node<T>* curr) {
	Node<T>* R = curr->right;
	if (curr == root) root = R;
	curr->right = R->left;
	L->left = curr;
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