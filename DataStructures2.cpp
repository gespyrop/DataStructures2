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
		//�� ��� ����� ����� �������� ���� main ���� ��������� �� ����� ��� b ��� c
		case 1:
			cout << "Insert b: ";
			cin >> b;
			cout << "Insert c: ";
			cin >> c;
			break;
		//�� ���� ����� ���� ��� ������ ���� main �������� � ���� ��� c
		case 2:
			cout << "Insert c: ";
			cin >> c;
			break;
		//����������� � ���� ��� b ������� ��� �� �� ����� ������ ��� � ���� ��� c ������� ��� �� �� ������� ������
		default:
			b = atof(argv[1]);
			c = atof(argv[2]);
	}

	BinarySearchTree<int> *B = new BinarySearchTree<int>(b, c);	//���������� �������� ������� ��������

	int element, choice = 5;	//� ��������� element ��������������� ���� ������� �� ������� ��������,�������� � ��������� ���� ���������
	//� ��������� choice ��������������� ��� ��� ������� ��� ������ ��� �������������� �� 5 ���� �� ������ ��� ������� ��� ����� ����

	//� ������� ������ ����� � ������ �� ����� 6
	while (choice != 6) {
		switch (choice) {
			//�� � ������ ����� 1 �������� ��� ��� ������ �� ����� ��� �������� ��� ��������
			case 1:
				cout << "\tInsert: ";
				cin >> element;
				B->addNode(element);
				break;
			//�� � ������ ����� 2 �������� ��� ��� ������ �� ����� ��� �������� ��� ��������
			case 2:
				cout << "\tDelete: ";
				cin >> element;
				B->deleteNode(element);
				break;
			//�� � ������ ����� 3 �������� ��� ��� ������ �� ����� ��� �������� ��� ���������
			case 3:
				cout << "\tSearch: ";
				cin >> element;
				cout << (B->search(element) ? "\nTrue: ":"\nFalse: ") << element << " is ";
				if (!B->search(element)) cout << "not ";
				cout << "in the tree!" << endl;
				break;
			//�� � ������ ����� 4 ����������� � ����������,����������� ��� ����������� ��� �������
			case 4:
				if (!B->isEmpty()) {
					cout << "\n\tPreorder: ";
					B->preorder();
					cout << "\n\tInorder: ";
					B->inorder();
					cout << "\n\tPostorder: ";
					B->postorder();
					cout << endl;
				}
				else cout << "The tree is empty!" << endl;
				break;
			//�� � ������ ����� 5 ������������ �� ������� ��� menu ��������
			case 5:
				cout << "\nOperations:\n\n\t1 Insert\n\t2 Delete\n\t3 Search\n\t4 Display\n\t5 Show Instructions\n\t6 Exit\n" << endl;
				break;
			//�� � ������� ����� ������������ ����� ������� ����� ��� 6 ����������� ������ ������
			default:
				cout << "Invalid choice!" << endl;
		}
		
		//�������� ��� ��� ������ � ������� �������
		cout << "\nChoose operation: ";
		cin >> choice;
	}

	delete B; //�������� ��� �������
	
	return 0;
}

