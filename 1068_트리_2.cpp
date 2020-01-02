#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int root;
int del;
vector<int> vec[51];
int par[51];

bool visit[51];
int cnt = 0;
void fuc(int now) {
	bool nothing = true;

	for (const auto & x : vec[now]) {
		if (x != del) {
			fuc(x);
			nothing = false;
		}
	}
	if (nothing) cnt++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, parent;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> parent;
		if (parent != -1) {
			vec[parent].push_back(i);
		}
		else {
			root = i;
		}
	}

	cin >> del;

	fill(visit, visit + 51, false);



	if (root == del) {
		cout << 0 << endl;
	}
	else {
		fuc(root);
		cout << cnt << endl;
	}

	return 0;
}