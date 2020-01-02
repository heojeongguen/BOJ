#include <iostream>
#include <algorithm>
using namespace std;

int dp[11];

//Å¾´Ù¿î
//int fuc(int now) {
//	if (now == 0) return 1;
//	if (now < 0) return 0;
//	return  fuc(now - 1) + fuc(now - 2) + fuc(now - 3);
//}
//
//int main() {
//	int T,N;
//	cin >> T;
//	while (T--) {
//		cin >> N;
//		fill(dp, dp + 11, 0);
//		cout << fuc(N) << "\n";
//	}
//}

int main() {
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		fill(dp, dp + 12, 0);
		dp[0] = 1;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= 3; j++) {
				if (i - j >= 0) dp[i] += dp[i - j];
			}
		}
		cout << dp[N] << "\n";
	}
}