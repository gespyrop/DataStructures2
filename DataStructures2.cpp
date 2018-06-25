#include "stdafx.h"
#include <iostream>
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"
#include "Stack.cpp"

using namespace std;

int main(int argc, char* argv[])
{
	float b, c;

	switch (argc) {
		case 1:
			cout << "Insert b: ";
			cin >> b;
			cout << "Insert c: ";
			cin >> c;
			break;
		case 2:
			cout << "Insert c: ";
			cin >> c;
			break;
		default:
			b = atof(argv[1]);
			c = atof(argv[2]);
	}

	BinarySearchTree<int> *B = new BinarySearchTree<int>(b, c);

	int element, choice = 4;

	while (choice != 5) {
		switch (choice) {
			case 1:
				cout << "\tInsert: ";
				cin >> element;
				B->addNode(element);
				break;
			case 2:
				cout << "\tDelete: ";
				cin >> element;
				B->deleteNode(element);
				break;
			case 3:
				if (!B->isEmpty()) {
					cout << "\tPreorder: ";
					B->preorder();
					cout << endl << "\tInorder: ";
					B->inorder();
					cout << endl << "\tPostorder: ";
					B->postorder();
					cout << endl;
				}
				else cout << "The tree is empty!" << endl;
				break;
			case 4:
				cout << "Operations:\n\n\t1 Insert Node\n\t2 Delete Node\n\t3 Display\n\t4 Show Instructions\n\t5 Exit\n" << endl;
				break;
			default:
				cout << "Invalid choice!" << endl;
		}

		cout << "\nChoose operation: ";
		cin >> choice;
	}

	delete B;
	
	return 0;
}

