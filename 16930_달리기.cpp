#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits.h>
#pragma warning(disable:4996)

using namespace std;
int dp[1001][1001];
char arr[1001][1001];
bool visit[1001][1001];
int R, C, K;
int X1, Y1, X2, Y2;
pair<int, int> dxdy[4] = { {1,0},{-1,0},{0,1},{0,-1} };
int cnt = 0;
int dfs( int r,  int c) {
	cout << r << "  " << c << endl;
	if (r == X2 && c == Y2) return 1;
	if (dp[r][c] != -1) return dp[r][c];

	visit[r][c] = true;
	dp[r][c] = INT_MAX;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= K; j++) {
			int nextR = r + dxdy[i].first * j;
			int nextC = c + dxdy[i].second * j;
			if (nextR <= 0 || nextR > R || nextC <= 0 || nextC > C) break;
			if (arr[nextR][nextC] != '.') break;
			if (visit[nextR][nextC] == true) continue;
			dp[r][c] = min(dp[r][c], 1 + dfs(nextR, nextC));
		}
	}
	visit[r][c] = false;
	return dp[r][c];
}

int main() {
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> R >> C >> K;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> X1 >> Y1 >> X2 >> Y2;
	int ans = dfs(X1, Y1);
	if (ans == INT_MAX) cout << -1 << endl;
	else cout << ans << endl;
}