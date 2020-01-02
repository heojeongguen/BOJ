#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;
int hei[101];
vector<int> vec[101];
int dp[101][501];

// 중복으로 탐색해도 상관없으니까
// k(bridge) 에따라서 탈출조건 해주면됨.
int dfs(int now, int bridge) {
	if (dp[now][bridge] != -1) return dp[now][bridge];
	if (bridge == 0) return hei[now];
	dp[now][bridge] = INT_MAX;
	for(int i = 0 ; i < vec[now].size(); i++){
		dp[now][bridge] = min(dp[now][bridge], dfs(vec[now][i], bridge - 1));
	}
	return dp[now][bridge];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp, -1, sizeof(dp));
	int N, M,a, b;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> hei[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	int T;
	cin >> T;
	int k;
	for (int i = 0; i < T; i++) {
		cin >> a >> k;
		int ans = dfs(a, k);
		if (ans == -1 || ans == INT_MAX) cout << -1 << endl;
		else cout << dfs(a, k) << endl;
		
	}
}