#include <iostream>
using namespace std;

int arr[101][101];
unsigned long long dp[101][101];
int N;

unsigned long long find(int row, int col) {
	if (row == N - 1 && col == N - 1) return 1;

	if (row < 0 || col < 0 || row >= N || col >= N || arr[row][col] == 0) return 0;

	if (dp[row][col] != -1) return dp[row][col];

	dp[row][col] = find(row + arr[row][col], col) + find(row, col + arr[row][col]);

	return dp[row][col];
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = -1;
		}
	}

	cout << find(0, 0) << endl;

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << endl;
	//}
}