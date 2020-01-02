#include <iostream>

using namespace std;

int dp[41];
int one[41];
int zero[41];
int fibonacci(int n) {
	if (dp[n] != 0) {
		return dp[n];
	}
	if (n == 0) {
		zero[n] = 1;
		return 0;
	}
	else if (n == 1) {
		one[n] = 1;
		return 1;
	}
	else {
		dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
		one[n] = one[n - 1] + one[n - 2];
		zero[n] = zero[n - 1] + zero[n - 2];
		return dp[n];
	}
}
int main() {
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		fibonacci(N);
		cout << zero[N] << " " << one[N]<< endl;
	}
}