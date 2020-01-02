#include <iostream>
#include <vector>
#include <algorithm>

/*
	���� ���� ���������� dfs�� �̿��ؼ� Ǯ����
	���� ������ ������ ���� : ����׷��� && cycle�� ���±׷���
	���� Ȯ��)
	1. ����׷��� : �������� �־���
	2. ����Ŭ�� ���±׷��� : dfs�� ���� Ȯ���ؾ���
*/

using namespace std;
vector<int> sd[32001];
bool visit[32001];
vector<int> ans[32001];
int dp[32001];
int par[32001];
int dfs(int v) {
	if (dp[v] != -1) return dp[v];

	if (sd[v].empty()) {
		dp[v] = 1;
		ans[1].push_back(v);
		return dp[v];
	}

	int ret = 0;
	for (int vv : sd[v]) {
			ret = 1 + max(ret, dfs(vv));
	}
	dp[v] = ret;
	ans[ret].push_back(v);
	return dp[v];
}

int main() {
	int N, M, d1, d2;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> d1 >> d2;
		sd[d1].push_back(d2);
		par[d2] = d1;
	}
	fill(dp + 1, dp + N + 1, -1);

	for (int i = 1; i <= N; i++) {
		if (par[i] == 0) {
			dfs(i);
		}
	}
	for (int i = N; i >= 1; i--) {
		for (int x : ans[i]) {
			cout << x << " ";
		}
	}
	return 0;
}