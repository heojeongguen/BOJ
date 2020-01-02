#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> map[100001];
vector<int> tmp;
int n, data1, data2;
int dp[100001][19];
int len;
int ans;

int fuc(int now, int prev_color, int prev_node) {
	if (dp[now][prev_color] != -1) return dp[now][prev_color];

	int ret = INT_MAX;

	bool nothing = true;

	for (int i = 1; i <= len; i++) {
		if (prev_color == i) continue;
		int temp = 0;

		for (int j = 0; j < map[now].size(); j++) {
			if (prev_node == map[now][j]) continue;
			temp += fuc(map[now][j], i, now);
			nothing = false;
		}
		if (temp == 0) continue;
		ret = min(ret, temp + i);
	}
	if (nothing) {
		tmp.clear();
		for (int i = 1; i <= len; i++) {
			if (i == prev_color) continue;
			tmp.push_back(i);
		}
		ret = *min_element(tmp.begin(), tmp.end());
		dp[now][prev_color] = ret;
		return 	dp[now][prev_color];
	}
	else {
		dp[now][prev_color] = ret;
		return dp[now][prev_color];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n;
	len = log2(n);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= len; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 1; i <= n - 1; i++) {
		cin >> data1 >> data2;
		map[data1].push_back(data2);
		map[data2].push_back(data1);
	}

	ans = fuc(1, 0, 0);
	cout << ans << "\n";
}