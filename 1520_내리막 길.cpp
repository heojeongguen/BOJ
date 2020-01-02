#include <iostream>
#include <algorithm>
using namespace std;


int arr[501][501];
int dp[501][501];
int M, N;
int ans = 0;
int fuc(int r, int c) {
	if (r < 1 || c < 1 || r > M || c > N) {
		return 0;
	}
	if (dp[r][c] != -1) return dp[r][c];

	if (r == M && c == N) {
		return 1;
	}


	dp[r][c] = 0;
	if (arr[r][c] > arr[r + 1][c])
		dp[r][c] += fuc(r + 1, c);

	if (arr[r][c] > arr[r - 1][c])
		dp[r][c] += fuc(r -1, c);

	if (arr[r][c] > arr[r][c+1])
		dp[r][c] += fuc(r, c + 1);

	if(arr[r][c] > arr[r][c-1])
		dp[r][c] += fuc(r , c -1 );

	return dp[r][c];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int data;
	cin >> M >> N;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = -1;
		}
	}
	cout << fuc(1, 1) << endl;
}