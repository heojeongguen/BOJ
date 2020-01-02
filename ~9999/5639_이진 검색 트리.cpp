#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Node {
public:
	Node *par;
	Node *left;
	Node *right;
	int data;
	Node(int data) {
		this->data = data;
		right = NULL;
		left = NULL;
		par = NULL;
	}	

};

class BST {
public:
	Node * root;
	BST() {
		this->root = NULL;
	}
	BST(int data) {
		Node * newNode = new Node(data);
		this->root = newNode;
	}
	void insert(int data) {
		Node * newNode = new Node(data);
		insert(this->root, newNode);
	}
	void insert(Node * r, Node * newNode) {
		if (r->data  >  newNode->data) {
			if (r->left == NULL) {
				r->left = newNode;
				newNode->par = r;
			}
			else {
				insert(r->left, newNode);
			}
		}
		else {
			if (r->right == NULL) {
				r->right = newNode;
				newNode->par = r;
			}
			else {
				insert(r->right, newNode);
			}
		}
	}
	void post(Node * root) {
		if (root->left != NULL) post(root->left);
		if (root->right != NULL) post(root->right);
		cout << root->data << "\n";
	}
};


int main() {
	int data;
	BST bst;
	while (cin >> data) {
		if (bst.root == NULL) {
			bst = BST(data);
		}
		else {

			bst.insert(data);
		}
	}
	bst.post(bst.root);
	return 0;
}