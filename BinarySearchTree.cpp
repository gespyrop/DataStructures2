#include "stdafx.h"
#include "BinarySearchTree.h"

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
	this->d = 0;
	this->n = 0;
}

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
	if (root == NULL) root = new Node<T>(data);	//Αν το δένδρο είναι κενό ο νέος κόμβος γίνεται ρίζα του
	else addNode(data, root);					//Αλλιώς ξεκινάμε απο την ρίζα
}

template <class T>
void BinarySearchTree<T>::addNode(const T& data, Node<T>* curr) {
	int depth = 0;			//Βάθος του νέου κόμβου
	Stack<Node<T>*>* path = new Stack<Node<T>*>;	//Στοίβα ώστε να κρατάμε το μονοπάτι (απο την ρίζα μέχρι το τελευταίο στοιχείο πριν το νέο φύλο)
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
	
	//Αν ισχύει η συνθήκη για το βάθος
	if (depth > c * log2(n + 1 + d)) {
		int height = 1;				//Ύψος κόμβου που ελέγχουμε
		Node<T>* v = path->pop();	//Κόμβος που ελέγχουμε
		int nv = subtreeElements(v);//Αριθμός στοιχείων υποδένδρου με ρίζα v

		//Όσο το ύψος έιναι μικρότερο απο την απαιτούμενη ποσότητα
		while (height <= c * log2(nv + 1) && !path->isEmpty()) {
			height++;	//Αυξάνουμε το ύψος κατα 1 (αφου μετακινούμαστε στον απο πάνω κόμβο)
			v = path->pop();	//Παίρνουμε τον επόμενο δέικτη σε κόμβο απο την στοίβα
			nv = subtreeElements(v);	//Και υπολογίζουμε τον νέο αριθμό στοιχείων του υποδένδρου
		}
		if (!path->isEmpty()) {	//Αν δεν έχει αδειάσει η στοίβα,δηλαδή δεν είμαστε στην ρίζα
			Node<T>* parent = path->pop();
			if (v->data < parent->data) parent->left = reconstruct(v);	//Συνθήκες για το άν ο κόμβος v είναι αριστερό η δεξί παιδί του πατέρα του
			else parent->right = reconstruct(v);	//Ανακατασκευάζουμε το υποδένδρο με ρίζα v και γίνεται ένωση του πατέρα με την νέα ρίζα
		}
		else root = reconstruct(root);	//Αλλιώς (αν είμαστε στην ρίζα) ανακατασκευάζουμε όλο το δένδρο
	}
	delete path;	//Διαγράφουμε την στοίβα
}

template <class T>
int BinarySearchTree<T>::subtreeElements(Node<T>* subtreeRoot) {
	if (subtreeRoot == NULL) return 0;	//Αν η ρίζα είναι NULL επιστρέφει 0
	else {
		//Αλλιώς επιστρέφει ανδρομικά των αριθμό των στοιχείων του αριστερόυ και του δεξιού υποδένδρου συν 1 (ρίζα)
		return subtreeElements(subtreeRoot->left) + subtreeElements(subtreeRoot->right) + 1;
	}
}

template <class T>
void BinarySearchTree<T>::deleteNode(const T& data) {
	deleteNode(data, root);	//Ψάχνουμε και διαγράφουμε τον κόμβο που θέλουμε ξεκινώντας (το ψάξιμο) απο την ρίζα
	//Μόλις η διαγραφή ολοκληρωθεί αν ο μετρητής d είναι μεγαλύτερο της απαιτούμενης ποσότητας
	if (d >= (pow(2, b / c) - 1) * (n + 1)) {
		root = reconstruct(root);	//Γίνεται ολική ανακατασκευή του δένδρου
		d = 0;						//Και ο μετρητής d γίνεται ίσος με 0
	}
}

template <class T>
void BinarySearchTree<T>::deleteNode(const T& data, Node<T>* curr) {
	//Αν το δένδρο δεν είναι άδειο
	if (root != NULL) {
		//Αν το στοιχείο που θέλουμε να διαγράψουμε είναι η ρίζα
		if (data == root->data) {
			Node<T>* delPtr = root;	//Δείκτης στην ρίζα
			T rootData = root->data;	//Στοιχείο που περιέχει η ρίζα
			T rsm;	//Right Subtree Minimum -> Το ελάχιστο στοιχείο του δεξιού υποδένδρου

			//Αν δεν έχει παιδία απλά την διαγράφουμε
			if (root->left == NULL && root->right == NULL) {
				root = NULL;
				delete delPtr;
			}
			//Αν έχει ένα παιδί αυτό γίνεται η νέα ρίζα
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
			//Αν έχει δύο παιδιά το ελάχιστο στοιχείο του δεξιού υποδένδρου παίρνει την θέση της
			else {
				rsm = subtreeMin(root->right);
				deleteNode(rsm);	//Διαγραφή ελάχιστου κόμβου δεξιού υποδένδρου
				root->data = rsm;	//Αποθήκευση του στοιχείου του στην ρίζα
			}
		}

		//Αν δέν είναι στην ρίζα
		else {
			//Αν είναι μικρότερο κινούμαστε προς τα αριστερά
			if (data < curr->data && curr->left != NULL) {
				//Όταν το βρούμε
				if (data == curr->left->data) {
					d++;	//Αυξάνουμε το d κάτα 1 (μία διαγραφή)
					n--;	//και μειώνουμε το n κάτα 1 (μείον ένα στοιχείο)
					Delete(curr, curr->left);	//Και διαγράφουμε τον κόμβο
				}
				//Αν δεν το βρούμε,ίδια διαδικασία για το αριστερό υποδένδρο
				else deleteNode(data, curr->left);
			}
			//Αντίστοιχα αν είναι μεγαλύτερο κινούμστε προς τα δεξιά κάνοντας τις ίδιες διαδκασίες
			else if (data > curr->data && curr->right != NULL) {
				if (data == curr->right->data) {
					d++;
					n--;
					Delete(curr, curr->right);
				}
				else deleteNode(data, curr->right);
			}
			//Αν περάσουμε το φύλο δεν υπάρχει
			else cout << "\nThe tree doesn't contain " << data << "!" << endl;
		}
	}
	//Αν το δένδρο είναι άδειο δεν υπάρχει
	else cout << "\nThe tree doesn't contain " << data << "!" << endl;
}

template <class T>
void BinarySearchTree<T>::Delete(Node<T>* parent, Node<T>* target) {
	Node<T>* delPtr;				//Δείκτης στον κόμβο που θέλουμε να διαγράψουμε
	T targetData = target->data;	//Στοιχείο προς διαγραφή
	T rsm;						//Ελάχιστο στοιχείο δεξιού υποδένδρου

	//Αν δεν έχει παιδία απλά διαγράφεται
	if (target->left == NULL && target->right == NULL) {
		delPtr = target;
		if (parent->left == target) parent->left = NULL;
		else parent->right = NULL;
		delete delPtr;
	}
	//Αν έχει ένα δεξί παιδί
	else if (target->left == NULL && target->right != NULL) {
		//Αν ο κόμβος που διαγράφουμε είναι αριστερό παιδί το παιδί του γίνεται αριστερό παιδί του πατέρα
		if (parent->left == target) parent->left = target->right;
		//Ενώ αν είναι δεξί γίνεται δεξί παιδί του πατέρα
		else parent->right = target->right;
		target->right = NULL;
		delPtr = target;
		delete delPtr;
	}
	//Ίδια διαδικασία αν έχει ένα αριστερό παιδί
	else if (target->left != NULL && target->right == NULL) {
		if (parent->left == target) parent->left = target->left;
		else parent->right = target->left;
		target->left = NULL;
		delPtr = target;
		delete delPtr;
	}
	//Αν έχει δύο παιδία
	else {
		rsm = subtreeMin(target->right);
		deleteNode(rsm, target);	//Διαγράφουμε τον κόμβο με το ελάχιστο στοιχείο στο δεξί υποδένδρο
		target->data = rsm;			//Του οποίου το στοιχείο αντικαθιστά αυτό που θέλαμε να διαγράψουμε
	}

}

template <class T>
T BinarySearchTree<T>::subtreeMin(Node<T>* curr) {
	while (curr->left != NULL) curr = curr->left;	//Πηγαίνουμε όσο πιο αριστερά για να βρούμε το ελάχιστο στοιχείο
	return curr->data;
}

template <class T>
Node<T>* BinarySearchTree<T>::reconstruct(Node<T>* r) {
	int n = subtreeElements(r);	//Αριθμός στοιχείων υποδένδρου
	int index = 0;				
	Node<T>** arr = new Node<T>*[n]; //Πίνακας με pointers σε Nodes
	inorderToArray(r, arr, index);	//Γέμισμα του πίνακα με την ενδοδιάταξη του υποδένδρου
	return arrayToTree(arr, 0, n - 1);	//Επιστροφή της νέας ρίζας του υποδένδρου
}

template <class T>
void BinarySearchTree<T>::inorderToArray(Node<T>* r, Node<T>* arr[], int &index) {
	if (r == NULL) return;	//Αν η ρίζα είναι null (δηλαδή έχουμε φτάσει σε φύλο) η διαδικασία τερματίζει
	else {
		inorderToArray(r->left, arr, index);	//Αλλιώς πηγαίνουμε στο αριστερό παιδί (μέχρι να μήν υπάρχει αριστερό παιδί)
		arr[index++] = r;						//Το αποθηκεύουμε στην θέση του πίνακα με το αντίστοιχο index και το αυξάνουμε κατα 1
		inorderToArray(r->right, arr, index);	//Κάνουμε την ίδια διαδικασία για το δεξί παιδί του κόμβου
	}
}

template <class T>
Node<T>* BinarySearchTree<T>::arrayToTree(Node<T>* arr[], int start, int end) {
	if (start > end) return NULL;	//Αν έχουν χρησιμοποιηθεί όλοι οι κόμβοι του υποδένδρου (αρχή > τέλος) η διαδικασία τερματίζει
	int middle = ((start + end) / 2);	//Μέσαιο στοιχείο = (αρχή + τέλος)/2
	Node<T>* newRoot = arr[middle];		//Το μεσάιο γίνεται νέα ρίζα του υποδένδρου
	newRoot->left = arrayToTree(arr, start, middle - 1);	//Και όσα στοιχεία ειναι αριστερά της αποτελούν το αριστερό της υποδένδρο
	newRoot->right = arrayToTree(arr, middle + 1, end);		//Ενω όσα είναι δεξιά το δεξί της υποδένδρο
	return newRoot;	//Επιστρέφεται η νέα ρίζα
}

template <class T>
bool BinarySearchTree<T>::search(const T& data) {
	return search(data, root);	//Καλείται η μέθοδος search ξεκινώντας απο την ρίζα
}

template <class T>
bool BinarySearchTree<T>::search(const T& data, Node<T>* curr) {
	if (curr == NULL) return false;		//Αν φτάσουμε σε NULL το στοιχείο δεν υπάρχει
	else if (data == curr->data) return true;	//Αν βρούμε το στοιχείο υπάρχει άρα επιστρέγει true
	else if (data < curr->data) return search(data, curr->left);	//Αν το στοιχείο είναι μικρότερο απο αυτό του κύριου κόμβου πάμε αριστερά
	else return search(data, curr->right);	//Αν είναι μεγαλύτερο πάμε δεξιά
}

//Οι επόμενες τρείς μεθόδοι χωρίς ορίσματα καλούν τις αντίστοιχες μεθόδους με όρισμα την ρίζα
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
	cout << curr->data << " "; //Εκτυπώνεται το στοιχείο του τρέχοντος κόμβου
	preorder(curr->left);	//Πηγαίνουμε στο αριστερό του παιδί
	preorder(curr->right);	//Πηγαίνουμε στο δεξί του παιδί
}

template <class T>
void BinarySearchTree<T>::inorder(Node<T>* curr) {
	if (curr == NULL) return;
	inorder(curr->left);		//Πηγαίνουμε στο αριστερό του παιδί
	cout << curr->data << " "; //Εκτυπώνεται το στοιχείο του τρέχοντος κόμβου
	inorder(curr->right);	//Πηγαίνουμε στο δεξί του παιδί
}

template <class T>
void BinarySearchTree<T>::postorder(Node<T>* curr) {
	if (curr == NULL) return;
	postorder(curr->left);	//Πηγαίνουμε στο αριστερό του παιδί
	postorder(curr->right);	//Πηγαίνουμε στο δεξί του παιδί
	cout << curr->data << " ";	//Εκτυπώνεται το στοιχείο του τρέχοντος κόμβου
}

template <class T>
bool BinarySearchTree<T>::isEmpty() {
	return !root;	//Επιστρέφει true αν η ρίζα είναι NULL
}