#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> map[10001];
int ans[10001];
bool visit[10001];
int mmax = 0;
void dfs(int v) {
	visit[v] = true;
	for (int vv : map[v]) {
		if (!visit[vv]) {
			ans[vv]++;
			dfs(vv);
		}
	}
}
int main() {
	int N, M, data1, data2;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> data1 >> data2;
		map[data1].push_back(data2);
	}
	for (int i = 1; i <= N; i++) {
		fill(visit, visit + 10001, false);
		dfs(i);
	}
	mmax = *max_element(ans + 1, ans + N + 1);
	for (int i = 1; i <= N; i++) {
		if (mmax == ans[i]) cout << i << " ";
	}
	return 0;
}