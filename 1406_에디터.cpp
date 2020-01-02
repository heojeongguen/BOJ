#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------

class Node {
public:
	Node*next;
	Node*prev;
	char data;
	Node() {
		next = 0;
		prev = 0;
	}
	Node(char data) {
		this->data = data;
		next = 0;
		prev = 0;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	Node * tmp = new Node(' ');
	for (int i = 0; i < str.size(); i++) {
			Node *newNode = new Node(str[i]);
			tmp->next = newNode;
			newNode->prev = tmp;
			tmp = newNode;
	}
	Node * now = new Node();
	now = tmp;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		char tag; cin >> tag;
		if (tag == 'L') {
			if (now->prev != 0) {
				now = now->prev;
			}
		}
		else if (tag == 'D') {
			if (now->next != 0) {
				now = now->next;
			}
		}
		else if (tag == 'B') {
			if (now->prev != 0) {
				Node *prev = now->prev;
				Node *next = now->next;
				if (next != 0) {
					prev->next = next;
					next->prev = prev;
				}
				else {
					prev->next = 0;
				}
				now = prev;
			}
		}
		else {
			char data; cin >> data;
			Node * newNode = new Node(data);
			Node * next = now->next;
			if (next != 0) {
				next->prev = newNode;
				newNode->next = next;

				now->next = newNode;
				newNode->prev = now;
				now = newNode;
			}
			else {
				now->next = newNode;
				newNode->prev = now;
				now = newNode;
			}
		}
	}
	deque<char> dq;
	tmp = now;
	while (tmp != 0) {
		dq.push_back(tmp->data);
		tmp = tmp->next;
	}

	tmp = now->prev;

	while (tmp != 0) {
		dq.push_front(tmp->data);
		tmp = tmp->prev;
	}

	for (int i = 0; i < dq.size(); i++) {
		if (dq[i] == ' ') continue;
		cout << dq[i];
	}
	cout << endl;
}