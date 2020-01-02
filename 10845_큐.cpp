#include <string>
#include <queue>
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, data;
	string tag;
	queue<int> que;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tag;
		if (tag == "push") {
			cin >> data;
			que.push(data);
		}
		else if (tag == "front") {
			if (que.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << que.front() << "\n";
			}
		}
		else if (tag == "back") {
			if (que.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << que.back() << "\n";
			}
		}
		else if (tag == "pop") {
			if (que.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << que.front() << "\n";
				que.pop();
			}
		}
		else if (tag == "empty") {
			if (que.size() == 0) {
				cout << 1 << "\n";
			}
			else {
				cout << 0<< "\n";
			}
		}
		else if (tag == "size") {
				cout << que.size() << "\n";
		}
	}
}