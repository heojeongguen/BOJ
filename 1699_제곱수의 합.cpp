#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[100001];
int main() {
	cin >> N;
	// 1 -> 1^2
	// 2 -> 1^2 1^2;
	// 3 -> 1^1 1^1 1^1
	// 4 -> 2^2
	// 
	for (int i = 1; i * i <= N; i++) {
		dp[i*i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (dp[i] != 0) {
			for (int j = 1; i + j * j <= N; j++) {
				if (dp[i + j * j] == 0) dp[i + j * j] = dp[i] + 1;
				else dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
			}
		}

	}
	cout << dp[N] << endl;
}