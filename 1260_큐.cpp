#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
bool dp[10001];
vector<int> node[10001];

void DFS(int x) {
	if (dp[x] == true) {
		return;
	}
	cout << x << " ";
	dp[x] = true;
	for (const auto &data : node[x]) {
		if (dp[data] == false) {
			DFS(data);
		}
	}
}
void BFS(int x) {
	if (dp[x] == true) {
		return;
	}
	dp[x] = true;
	for (const auto &data : node[x]) {
		if (dp[data] == false) {
			cout << data << " ";
		}
	}
	for (const auto &data : node[x]) {
		if (dp[data] == false) {
			BFS(data);
		}
	}
}

void claer() {
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			dp[i] = false;
		}
	}
}

int main() {
	int N, M, V, data1, data2;
	cin >> N >> M >> V;
	for(int i = 0; i < M; i++){
		cin >> data1 >> data2;
		node[data1].push_back(data2);
		node[data2].push_back(data1);
	}
	for (int i = 1; i <= N; i++) {
		sort(node[i].begin(), node[i].end());
	}
	DFS(V);
	claer();
	cout << endl;
	queue<int> que;
	que.push(V);
	cout << V << " ";
	dp[V] = true;
	while (que.size() != 0) {
		int size = que.size();
		int origin = que.front();
		while(size--) {
			int tmp = que.front();
			que.pop();
			for (const auto &x : node[tmp]) {
				if (dp[x] == false) {
					cout << x << " ";
					que.push(x);
					dp[x] = true;
				}
			}
		}
	}
}