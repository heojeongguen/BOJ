#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string str;
	int dp[123];
	int time = 3;
	int count = 0;
	int ans = 0;
	for (int i = 65; i <= 90; i++) {
		if (count >= 3) {
			count = 0;
			time++;
		}
		if ((char)i != 'R' && (char)i != 'Y') {
			count++;
		}
		dp[i] = time;
	}

	cin >> str;
	for (const auto &x : str) {
		ans += dp[(int)x];
	}
	cout << ans << endl;
}