#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
vector<int> coin;
int dp[10001];

int main() {
	int N, M, D;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> D;
		coin.push_back(D);
	}
	for (int i = 1; i <= M; i++) {
		dp[i] = 10001;
	}
	for (const auto & x : coin) {
		for (int i = x; i <= M; i++) {
			dp[i] = min(dp[i], dp[i - x] + 1);
		}
	}



	if (dp[M] == 10001) cout << -1 << endl;
	else cout << dp[M] << endl;
	
}