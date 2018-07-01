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
		//Αν δεν έχουν δωθεί ορίσματα στην main τότε ζητούνται οι τιμές των b και c
		case 1:
			cout << "Insert b: ";
			cin >> b;
			cout << "Insert c: ";
			cin >> c;
			break;
		//Αν έχει δωθεί μόνο ένα όρισμα στην main ζητείται η τιμή του c
		case 2:
			cout << "Insert c: ";
			cin >> c;
			break;
		//Διαφορετικά η τιμή του b γίνεται ίση με το πρώτο όρισμα και η τιμή του c γίνεται ίση με το δεύτερο όρισμα
		default:
			b = atof(argv[1]);
			c = atof(argv[2]);
	}

	BinarySearchTree<int> *B = new BinarySearchTree<int>(b, c);	//Δημιουργία δυαδικού δένδρου ακεραίων

	int element, choice = 5;	//Η μεταβλητή element χρησιμοποιείται όταν θέλουμε να κάνουμε εισαγωγή,διαγραφή ή αναζήτηση ενός στοιχείου
	//Η μεταβλητή choice χρησιμοποιείται για την επιλογή του χρήστη και αρχικοποιείται με 5 ώστε να δείξει τις οδηγίες την πρώτη φορά

	//Ο βρόγχος τρέχει μέχρι η επλογή να γίνει 6
	while (choice != 6) {
		switch (choice) {
			//Αν η επλογή είναι 1 ζητείται απο τον χρήστη να δώσει ένα στοιχείο για εισαγωγή
			case 1:
				cout << "\tInsert: ";
				cin >> element;
				B->addNode(element);
				break;
			//Αν η επλογή είναι 2 ζητείται απο τον χρήστη να δώσει ένα στοιχείο για διαγραφή
			case 2:
				cout << "\tDelete: ";
				cin >> element;
				B->deleteNode(element);
				break;
			//Αν η επλογή είναι 3 ζητείται απο τον χρήστη να δώσει ένα στοιχείο για αναζήτηση
			case 3:
				cout << "\tSearch: ";
				cin >> element;
				cout << (B->search(element) ? "\nTrue: ":"\nFalse: ") << element << " is ";
				if (!B->search(element)) cout << "not ";
				cout << "in the tree!" << endl;
				break;
			//Αν η επλογή είναι 4 εμφανίζεται η προδιάταξη,ενδοδιάταξη και μεταδιάταξη του δένδρου
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
			//Αν η επλογή είναι 5 εμφανίζονται οι οδηγίες του menu επιλογών
			case 5:
				cout << "\nOperations:\n\n\t1 Insert\n\t2 Delete\n\t3 Search\n\t4 Display\n\t5 Show Instructions\n\t6 Exit\n" << endl;
				break;
			//’ν η επιλογή είναι οποιοσδήποτε άλλος αριθμός εκτός του 6 εμφανίζεται μήνυμα λάθους
			default:
				cout << "Invalid choice!" << endl;
		}
		
		//Ζητείται απο τον χρήστη η επόμενη επιλογή
		cout << "\nChoose operation: ";
		cin >> choice;
	}

	delete B; //Διαγραφή του δένδρου
	
	return 0;
}

