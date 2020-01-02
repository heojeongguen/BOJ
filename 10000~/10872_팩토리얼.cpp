#include <iostream>

using namespace std;
unsigned long long dp[12];
int main() {
	int N;
	unsigned long long ans = 1;
	cin >> N;
	for (int i = N; i >= 1; i--) {
		ans *= i;
	}
	cout << ans << endl;
}