#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define endl '\n'
typedef long long ll;

vector<int> vec;

// w번움직였을때 현재위치

int T, W;
int dp[3][31][1001];

int fun(int n, int w, int t) {
	if (t >= T) return 0;

	int& ret = dp[n][w][t];
	if (ret != -1) return ret;

	int tmp1, tmp2;
	if (vec[t] == n) {
		tmp1 = 1;
		tmp2 = 0;
	}
	else {
		tmp1 = 0;
		tmp2 = 1;
	}
	ret = tmp1 + fun(n, w, t + 1);
	if (w > 0) {
		(n == 1) ? n = 2 : n = 1;
		ret = max(ret, tmp2 + fun(n, w - 1, t + 1));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> T >> W;
	for (int i = 0; i < T; i++) {
		int data; cin >> data;
		vec.push_back(data);
	}
	cout << fun(1, W, 0) << endl;
}