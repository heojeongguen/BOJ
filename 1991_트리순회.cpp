#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	Node *left;
	Node *right;
	Node *par;
	char data;
	Node(char data) {
		this->left = 0;
		this->right = 0;
		this->data = data;
	}
	Node * getLeft() {
		return this->left;
	}
	Node * getRight() {
		return this->right;
	}
	Node * setPar(Node *par) {
		this->par = par;
	}
	char retrieve() {
		return this->data;
	}
	void setLeft(Node * left) {
		if (left->data == '.') {
			left = 0;
		}
		else {
			left->par = this;
			this->left = left;
		}
	}
	void setRight(Node * right) {
		if (right->data == '.') {
			right = 0;
		}
		else {
			right->par = this;
			this->right = right;
		}
	}

	bool leaf() {
		return left == 0 && right == 0;
	}

};

class Tree {
public:
	Node * root;
	Tree() {
		this->root = 0;
	}
	Tree(Node * root) {
		this->root = root;
	}
	Node* getRoot() {
		return this->root;
	}
	void pre(Node * root) {
		cout << root->data;
		if (root->leaf()) return;

		if (root->getLeft() != 0) {
			pre(root->getLeft());
		}
		if (root->getRight() != 0) {
			pre(root->getRight());
		}
	}

	void inorder(Node * root) {
		if (root->getLeft() != 0) {
			inorder(root->getLeft());
		}
		cout << root->data;
		if (root->getRight() != 0) {
			inorder(root->getRight());
		}
	}

	void post(Node * root) {
		if (root->getLeft() != 0) {
			post(root->getLeft());
		}
	
		if (root->getRight() != 0) {
			post(root->getRight());
		}
		cout << root->data;
	}
};

int main() {
	vector<Node *> list;
	int N;
	cin >> N;
	char a, b, c;
	Tree tree;
	while (N--) {
		cin >> a >> b >> c;
		Node * root = NULL;
		Node * left = new Node(b);
		Node * right = new Node(c);
		if (tree.getRoot() == 0) {
			Node * root = new Node(a);
			tree = Tree(root);
			list.push_back(root);
			if (b != '.') {
				list.push_back(left);
				root->setLeft(left);
			}
			if (c != '.') {
				list.push_back(right);
				root->setRight(right);
			}
		}
		else {
			for (const auto &x : list) {
				if (x->data == a) {
					root = x;
					break;
				}
			}
			
			if (root == 0) {
				Node * root = new Node(a);
				list.push_back(root);
			}

			if (b != '.') {
				list.push_back(left);
				root->setLeft(left);
			}
			if (c != '.') {
				list.push_back(right);
				root->setRight(right);
			}
		
		}
	}
	tree.pre(tree.getRoot());
	cout << endl;
	tree.inorder(tree.getRoot());
	cout << endl;
	tree.post(tree.getRoot());
	cout << endl;
}
