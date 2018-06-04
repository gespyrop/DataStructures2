#include "stdafx.h"
#include <iostream>
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"

using namespace std;

int main(int argc, char* argv[])
{
	float b = atof(argv[1]);
	float c = atof(argv[2]);
	BinarySearchTree <int> B(b, c);

	B.addNode(50);
	B.addNode(12);
	B.addNode(6);
	B.addNode(90);
	B.addNode(34);
	B.addNode(55);
	B.addNode(125);
	B.addNode(90);
	B.addNode(250);
	B.addNode(3);
	B.deleteNode(55);
	B.deleteNode(125);

	cout << "Preorder: ";
	B.preorder();
	cout << endl << "Inorder: ";
	B.inorder();
	cout << endl << "Postorder: ";
	B.postorder();
	cout << endl;
	return 0;
}

