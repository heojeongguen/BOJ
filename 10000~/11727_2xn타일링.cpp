#include <iostream>
#include <deque>
using namespace std;

int dp[1001] = { 0, };

int tileing(int n) {
	if (dp[n] != -1) {
		return dp[n];
	}
	if (n == 1) {
		dp[1] = 1;
		return 1;
	}
	else if (n == 2) {
		dp[2] = 3;
		return 3;
	}
	else {
		return dp[n] = (tileing(n-1) + 2 *tileing(n-2)) % 10007;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = -1;
	}
	cout << tileing(n);
}