#include <iostream>

using namespace std;

int R, C;
int arr[501][501];
int dp[501][501];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int dfs(int nowR,int nowC) {
	if (nowR == R && nowC == C) return 1;
	if (nowR > R || nowR <= 0 || nowC > C || nowC <= 0) return 0;

	if (dp[nowR][nowC] != -1) return dp[nowR][nowC];
	int result = 0;
	for (int i = 0; i < 4; i++) {
		int nextR = nowR + dx[i];
		int nextC = nowC + dy[i];
		if (arr[nextR][nextC] < arr[nowR][nowC]) {
			result += dfs(nextR, nextC);
		}
	}
	dp[nowR][nowC] = result;
	return dp[nowR][nowC];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
	cout << dfs(1, 1) << "\n";
}