#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	int N,data;
	deque<int> dq;
	string tag;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tag;
		if (tag == "push_front") {
			cin >> data;
			dq.push_front(data);
		}else if (tag == "push_back") {
			cin >> data;
			dq.push_back(data);
		}
		else if (tag == "pop_front") {
			if (dq.size() == 0) {
				cout << -1 << endl;
			}
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (tag == "pop_back") {
			if (dq.size() == 0) {
				cout << -1 << endl;
			}
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if (tag == "size") {
			cout << dq.size() << endl;
		}
		else if (tag == "empty") {
			if (dq.size() == 0) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (tag == "front") {
			if (dq.size() == 0) {
				cout << -1 << endl;
			}
			else {
				cout << dq.front() << endl;
			}
		}
		else if (tag == "back") {
			if (dq.size() == 0) {
				cout << -1 << endl;
			}
			else {
				cout << dq.back() << endl;
			}
		}
	}
}