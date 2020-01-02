#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> root;
int del;
vector<int> vec[51];
int par[51];

bool visit[51];
int cnt = 0;
void fuc(int now) {
	visit[now] = true;


	if (now == del) {
		return;
	}

	bool nothing = true;

	for (int i = 0; i < vec[now].size(); i++) {
		if (visit[vec[now][i]] == false) {
			if (vec[now][i] != del) {
				fuc(vec[now][i]);
				nothing = false;
			}
		}
	}
	if (nothing) cnt++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N,parent;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> parent;
		if (parent != -1) {
			vec[parent].push_back(i);
		}
		par[i] = parent;
	}

	cin >> del;

	fill(visit, visit + 51, false);

	for (int i = 0; i < N; i++) {
		if (par[i] == -1) {
			root.push(i);
		}
	}

	while (!root.empty()) {
		fuc( root.front() ); root.pop();
	}
	cout << cnt << endl;
	return 0;
}