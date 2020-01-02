#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> ans;
bool dp[10001];

void fuc(int x) {
	if (x >= 10000) return;

	if (dp[x]) return;

	dp[x] = true;

	int size = log10(x);
	int temp;
	int origin = x;
	int result = 0;
	for (int i = pow(10, size); i >= 1; i /= 10) {
		temp = (x / i);
		result += temp;
		x -= temp * i;
	}
	result += origin;
	fuc(result);
}

int main() {
	for (int i = 0; i <= 10000; i++) {
		dp[i] = false;
	}
	for (int i = 1; i < 10000; i++) {
		if (dp[i] == false) {
			ans.push_back(i);
			fuc(i);
		}
	}
	sort(ans.begin(), ans.end());
	for (const auto &x : ans) {
		cout << x << endl;
	}
}