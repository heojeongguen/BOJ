#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int time[501];
vector<int> map[501];
int dp[501];
int dfs(int v) {
	if (dp[v] != -1) return dp[v];

	if (map[v].empty()) {
		dp[v] = time[v];
		return dp[v];
	}

	int ret = 0;
	for (int vv : map[v]) {
		ret = max(ret, time[v]  + dfs(vv));
	}
	dp[v] = ret;
	return dp[v];
}

int main() {
	int N,d, t;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> t;
		time[i] = t;
		while (true) {
			cin >> d;
			if (d == -1) break;
			map[i].push_back(d);
		}
	}
	fill(dp + 1, dp + 1 + N, -1);
	for (int i = 1; i <= N; i++) {
		if(dp[i] == -1)	 dfs(i);
	}
	for (int i = 1; i <= N; i++) {
		cout << dp[i] << " ";
	}
}