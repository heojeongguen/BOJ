#include <iostream>

using namespace std;

int main() {
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		int dp[12];
		fill(dp, dp + 12, 0);
		dp[0] = 1;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= 3; j++) {
				if (i - j >= 0) dp[i] += dp[i - j];
			}
		}
		cout << dp[N] << endl;
	}
}