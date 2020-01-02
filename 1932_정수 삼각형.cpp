#include <iostream>
#include <algorithm>
using namespace std;
int dp[501][501] = { 0, };
int a[501][501];
int N;
int tri(int r, int c) {
	if (dp[r][c] != 0) return dp[r][c];

	if (r == N - 1) {
		return a[r][c];
	}

	dp[r][c] = a[r][c] + max(tri(r + 1, c), tri(r + 1, c + 1));
	return dp[r][c];
}

int main() {
	int data;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> data;
			a[i][j] = data;
		}
	}


	cout << tri(0, 0) << endl;
}