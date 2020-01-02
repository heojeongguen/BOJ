#include <iostream>

using namespace std;

int N;
int arr[101][101];
unsigned long long dp[101][101];
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
unsigned long long dfs(int nowR, int nowC) {
	if (nowR == N && nowC == N) return 1;
	if (arr[nowR][nowC] == 0) return 0;
	if (nowR > N || nowR <= 0 || nowC > N || nowC <= 0) return 0;
	if (dp[nowR][nowC] != -1) return dp[nowR][nowC];
	unsigned long long ret = 0;
	for (int i = 0; i < 2; i++) {
		int nextR = nowR + dx[i] * arr[nowR][nowC];
		int nextC = nowC + dy[i] * arr[nowR][nowC];
		ret += dfs(nextR, nextC);
	}
	dp[nowR][nowC] = ret;
	return ret;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
	cout << dfs(1, 1) << "\n";
	return 0;
}