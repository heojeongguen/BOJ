#include <iostream>

using namespace std;

int dp[1001][1001];

int main() {
	int N, K;
	cin >> N >> K;
	unsigned long long ans = 1;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			dp[i][j] = 1;
		}
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	cout << dp[N][K] << endl;
}