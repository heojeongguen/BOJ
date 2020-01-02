#include <iostream>
#include <algorithm>

using namespace std;

class Node {
public:
	Node * left;
	Node * right;
	Node * par;
	int data;
	Node(int data) {
		this->left = 0;
		this->right = 0;
		this->par = 0;
		this->data = data;
	}
};
class BST {
public:

	Node * root;
	BST() {
		this->root = 0;
	}
	BST(int data) {
		Node * newNode = new Node(data);
		this->root = newNode;
	}

	void insert(int data) {
		Node * newNode = new Node(data);
		insert(this->root, newNode);
	}

	void insert(Node * par, Node * newNode) {
		if (par->data < newNode->data) {
			if (par->right == 0) {
				par->right = newNode;
				newNode->par = par;
			}
			else {
				insert(par->right, newNode);
			}
		}else if (par->data > newNode->data) {
			if (par->left == 0) {
				par->left = newNode;
				newNode->par = par;
			}
			else {
				insert(par->left, newNode);
			}
		}
	}

	void post(Node * par) {
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		if (par->left != 0) {
			post(par->left);
		}
		if (par->right != 0) {
			post(par->right);
		}
		cout << par->data << "\n";
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int data;
	BST bst;
	while (cin >> data) {
		if (bst.root == 0) {
			bst = BST(data);
		}
		else {
			bst.insert(data);
		}
	}
	bst.post(bst.root);
	return 0;
}