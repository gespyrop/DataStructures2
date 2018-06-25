#include "stdafx.h"
#include "BinarySearchTree.h"

//Default constructor
template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
	this->d = 0;
	this->n = 0;
}

//Constructor με ορίσματα
template <class T>
BinarySearchTree<T>::BinarySearchTree(float b, float c)
{
	root = NULL;
	this->d = 0;
	this->n = 0;
	this->b = b;
	this->c = c;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
	delete root;
}

template <class T>
void BinarySearchTree<T>::addNode(const T& data) {
	n++;
	if (root == NULL) root = new Node<T>(data);	//Αν το δέντρο είναι κενό ο νέος κόμβος γίνεται ρίζα του
	else addNode(data, root);					//Αλλιώς ξεκινάμε απο την ρίζα
}

template <class T>
void BinarySearchTree<T>::addNode(const T& data, Node<T>* curr) {
	int depth = 0;			//Βάθος του νέου κόμβου
	Stack<Node<T>*>* path = new Stack<Node<T>*>;	//Στοίβα ώστε να κρατάμε το μονοπάτι
	while (true) {
		depth++;			//Αυξάνουμε το βάθος κάτα 1
		path->push(curr);	//Προστείθεται ο κόμβος στο μονοπάτι
		if (data == curr->data) {	//Αν το στοιχείο υπάρχει ήδη στο δέντρο η διαδικασιία τερματίζει
			n--;					//Το n μειώνεται κατα 1 αφου τελίκα το νέο στοιχείο δεν εισάγεται
			return;
		}
		else if (data < curr->data) {	//Αν έιναι μικρότερο του στοιχείου που βρισκόμαστε
			if (curr->left == NULL) {	
				curr->left = new Node<T>(data);	//Αν δεν έχει αριστερό παιδί το νέο στοιχείο γίνεται αριστερό του παιδί
				break;
			}
			else curr = curr->left;		//Αλλιώς πηγάινουμε στο αριστερό του παιδί
		}
		else {							//Αν έιναι μεγαλύτερο του στοιχείου που βρισκόμαστε
			if (curr->right == NULL) {
				curr->right = new Node<T>(data); //Αν δεν έχει δεξί παιδί το νέο στοιχείο γίνεται δεξί του παιδί
				break;
			}
			else curr = curr->right; //Αλλιώς πηγάινουμε στο δεξί του παιδί
		}
	}
	if (depth > c * log2(n + 1 + d)) {
		int height = 1;
		Node<T>* v = path->pop();
		int nv = subtreeElements(v);
		while (height <= c * log2(nv + 1) && !path->isEmpty()) {
			height++;
			v = path->pop();
			nv = subtreeElements(v);
		}
		if (!path->isEmpty()) {
			Node<T>* parent = path->pop();
			if (v->data < parent->data) parent->left = reconstruct(v);
			else parent->right = reconstruct(v);
		}
		else root = reconstruct(root);
	}
	delete path;
} 

template <class T>
int BinarySearchTree<T>::subtreeElements(Node<T>* subtreeRoot) {
	if (subtreeRoot == NULL) return 0;
	else {
		return subtreeElements(subtreeRoot->left) + subtreeElements(subtreeRoot->right) + 1;
	}
}

template <class T>
void BinarySearchTree<T>::deleteNode(const T& data) {
	deleteNode(data, root);
	if (d >= (pow(2, b / c) - 1) * (n + 1)) {
		root = reconstruct(root);
		d = 0;
	}
}

template <class T>
void BinarySearchTree<T>::deleteNode(const T& data, Node<T>* curr) {
	if (root != NULL) {
		if (data == root->data) {
			deleteRoot();
		}
		else {
			if (data < curr->data && curr->left != NULL) {
				if (data == curr->left->data) {
					d++;
					n--;
					Delete(curr, curr->left);
				}
				else deleteNode(data, curr->left);
			}
			else if (data > curr->data && curr->right != NULL) {
				if (data == curr->right->data) {
					d++;
					n--;
					Delete(curr, curr->right);
				}
				else deleteNode(data, curr->right);
			}
			else {
				cout << "The tree doesn't contain " << data << "!" << endl;
			}
		}
	}
	else cout << "The tree doesn't contain " << data << "!" << endl;;
}

template <class T>
void BinarySearchTree<T>::deleteRoot() {
	if (root != NULL) {
		Node<T>* delPtr = root;
		int rootData = root->data;
		int rsm;

		if (root->left == NULL && root->right == NULL) {
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
Node<T>* BinarySearchTree<T>::reconstruct(Node<T>* r) {
	int n = subtreeElements(r);
	int index = 0;
	Node<T>** arr = new Node<T>*[n];
	inorderToArray(r, arr, index);
	return arrayToTree(arr, 0, n - 1);
}

template <class T>
void BinarySearchTree<T>::inorderToArray(Node<T>* r, Node<T>* arr[], int &index) {
	if (r == NULL) return;
	else {
		inorderToArray(r->left, arr, index);
		arr[index++] = r;
		inorderToArray(r->right, arr, index);
	}
}

template <class T>
Node<T>* BinarySearchTree<T>::arrayToTree(Node<T>* arr[], int start, int end) {
	if (start > end) return NULL;
	int middle = ((start + end) / 2);
	Node<T>* newRoot = arr[middle];
	newRoot->left = arrayToTree(arr, start, middle - 1);
	newRoot->right = arrayToTree(arr, middle + 1, end);
	return newRoot;
}

template <class T>
bool BinarySearchTree<T>::search(const T& data) {
	return search(data, root);
}

template <class T>
bool BinarySearchTree<T>::search(const T& data, Node<T>* curr) {
	if (curr == NULL) return false;
	else if (data == curr->data) return true;
	else if (data < curr->data) return search(data, curr->left);
	else return search(data, curr->right);
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

template <class T>
bool BinarySearchTree<T>::isEmpty() {
	return !root;
}