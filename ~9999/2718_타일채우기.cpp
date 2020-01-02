#include <iostream>

using namespace std;

int dp[1001];

int fuc(int now) {
	if (dp[now] != 0) return dp[now];
	if (now == 1) return 1;
	if (now == 2) return 5;
	if (now == 3) return 11;
	dp[now] = fuc(now - 1) + 4 * fuc(now - 2);
	dp[now] += 4;
		//dp[now] = fuc(now - 1) + 4 * fuc(now - 2);


	return dp[now];
}

int main() {
	int T,N;
	cin >> T;
	while (T--) {
		cin >> N;
		cout << fuc(N) << endl;
	}
}
