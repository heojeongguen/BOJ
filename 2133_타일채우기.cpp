#include <iostream>
#include <algorithm>
using namespace std;

int N;
unsigned long long dp[31];
int fuc(int now){
	if (now <= 0) return 1;

	if (dp[now] != -1) return dp[now];

	if (now % 2 == 1) return 0;

	if (now == 2) return 3;

	if (now == 4) return 11;

	dp[now] = 3 * fuc(now - 2);
	for (int i = now - 4; i >= 0; i -= 2) {
		dp[now] += 2 * fuc(i);
	}

	return dp[now];
}

int main() {
	cin >> N;
	fill(dp, dp + 31, -1);
	cout << fuc(N) << endl;
}