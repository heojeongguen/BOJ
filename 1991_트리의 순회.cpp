#include <iostream>
#include <vector>
using namespace std;

pair<int,int> tree[26];

void pre(int now) {
	if (now == -19) return;
	cout << (char)(now + 65);
	pre(tree[now].first);
	pre(tree[now].second);
}

void mid(int now) {
	if (now == -19) return;
	mid(tree[now].first);
	cout << (char)(now + 65);
	mid(tree[now].second);

}

void post(int now) {
	if (now == -19) return;
	post(tree[now].first);
	post(tree[now].second);
	cout << (char)(now + 65);

}

int main() {
	// 전위수니회
	// 중위순회
	// 후위순회
	int N;
	char root, left, right;
	for (int i = 0; i < 26; i++) {
		tree[i].first = -19;
		tree[i].second = -19;
	}
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> root >> left >> right;
		int root_id = (int)root - 65;
		int left_id = (int)left - 65;
		int right_id = (int)right - 65;
		tree[root_id].first = left_id;
		tree[root_id].second = right_id;
	}
	pre(0);
	cout << endl;
	mid(0);
	cout << endl;
	post(0);
	cout << endl;
}