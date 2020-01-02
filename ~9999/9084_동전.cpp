#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001];

int main() {
	int T, N, D, K;

	vector<int> coin;
	cin >> T;
	while (T--) {
		coin.clear();
		fill(dp, dp + 10001, 0);
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> D;
			coin.push_back(D);
		}
		cin >> K;
		dp[0] = 1;
		for (int i = 0; i < coin.size(); i++) {
			for (int j = coin.at(i); j <= K; j++) {
				dp[j] += dp[j - coin.at(i)];
			}
		}

		cout << dp[K] << endl;
	}
}