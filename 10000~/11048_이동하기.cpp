#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
int arr[1001][1001];
int dp[1001][1001];
int dfs(int nowR,int nowC) {
	if (dp[nowR][nowC] != -1) return dp[nowR][nowC];

	if (nowR > R || nowC > C || nowR < 0 || nowC < 0) return 0;

	dp[nowR][nowC] = arr[nowR][nowC] + max({ dfs(nowR + 1,nowC),dfs(nowR,nowC + 1), dfs(nowR + 1,nowC + 1) });

	return dp[nowR][nowC];
}

int main() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
		}
	}
	cout << dfs(1, 1) << endl;
}