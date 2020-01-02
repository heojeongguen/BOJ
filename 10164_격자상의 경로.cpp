#include <iostream>
#include <algorithm>
using namespace std;
int arr[16][16];
int dp[16][16];
int R, C, K;
int Kr, Kc;
int dfs(int nowR, int nowC) {
	if (nowR > Kr || nowC > Kc) return 0;

	if (dp[nowR][nowC] != -1) return dp[nowR][nowC];

	if (nowR == Kr && nowC == Kc) {
		return 1;
	}
	int ret = 0;

	ret += dfs(nowR, nowC + 1);
	ret += dfs(nowR + 1, nowC);
	return ret;
}

int dfs2(int nowR, int nowC) {
	if (nowR > R || nowC > C) {
		return 0;
	}

	if (dp[nowR][nowC] != -1) {
		return dp[nowR][nowC];
	}

	if (nowR == R && nowC == C) {
		dp[nowR][nowC] = 1;
		return dp[nowR][nowC];
	}
	int ret = 0;
	ret += dfs2(nowR, nowC + 1);
	ret += dfs2(nowR + 1, nowC);
	return ret;
}
int main() {

	cin >> R >> C >> K;

	int cnt = 1;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (cnt == K) {
				Kr = i;
				Kc = j;
			}
			arr[i][j] = cnt;
			dp[i][j] = -1;
			cnt++;
		}
	}
	if (K == 0) {
		cout << dfs2(1, 1) << endl;
	}
	else {
		cout << dfs(1, 1) * dfs2(Kr, Kc) << endl;

	}


}