#include <iostream>

using namespace std;

int N;

unsigned long long arr[101];
unsigned long long dp[101][1001];

unsigned long long dfs(int now, int add) {
	if (add < 0 || add > 20) return 0;

	if (now == N - 1) {
		if (add == arr[N]) {
			dp[now][add] = 1;
		}
		else {
			dp[now][add] = 0;
		}
		return dp[now][add];
	}

	if (dp[now][add] != -1) return dp[now][add];



	unsigned long long ret = 0;

	ret += dfs(now + 1, add - arr[now + 1]);

	ret += dfs(now + 1, add + arr[now + 1]);

	dp[now][add] = ret;

	return dp[now][add];
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];

	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= 20; j++) {
			dp[i][j] = -1;
		}
	}
	cout << dfs(1, arr[1]) << endl;
}