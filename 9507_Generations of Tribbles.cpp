#include <iostream>

using namespace std;

unsigned long long dp[70];

unsigned long long koong(int now) {
	if (dp[now] != 0) return dp[now];
	if (now < 2) return 1;
	if (now == 2) return 2;
	if (now == 3) return 4;
	dp[now] = koong(now - 1) + koong(now - 2) + koong(now - 3) + koong(now - 4);
	return dp[now];
}

int main() {
	int T, N, K;
	cin >> T;
	while (T--) {
		cin >> N;
		cout << koong(N) << endl;
	}
}