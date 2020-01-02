#include <iostream>

using namespace std;

int dp[5001];

int main() {
	int N ,count = 0;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		dp[i] = -1;
	}
	dp[3] = 1;
	dp[5] = 1;
	
	// 3kg
	for (int i = 1; i <= N; i++) {
		if (dp[i] == -1) {
			continue;
		}
		else {
			for (int j = i,  count = 0; j <= N; j = j + 3, count++) {
				if (dp[j] == -1) {
					dp[j] = dp[i] + count;
				}
				else {
					if (dp[j] > dp[i] + count ) {
						dp[j] = dp[i] + count ;
					}
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (dp[i] == -1) {
			continue;
		}
		else {
			for (int j = i, count = 0; j <= N; j = j + 5, count++) {
				if (dp[j] == -1) {
					dp[j] = dp[i] + count;
				}
				else {
					if (dp[j] > dp[i] + count) {
						dp[j] = dp[i] + count;
					}
				}
			}
		}
	}

	cout << dp[N];
}