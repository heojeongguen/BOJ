#include <iostream>
#include <algorithm>
using namespace std;

int head = -1;
int cloth = -1;

int main() {
	int N, Q, D;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> D;
		head = max(head, D);
	}
	for (int i = 0; i < Q; i++) {
		cin >> D;
		cloth = max(cloth, D);
	}
	cout << head + cloth << endl;
	return 0;
}