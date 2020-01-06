	#include <iostream>
	#include <vector>
	#include <string>
	#include <algorithm>
	#include <queue>
	#include <cstring>
	using namespace std;

	#define endl '\n'
	typedef long long ll;

	ll dp[101][101][101];

	int N, R, L;
	ll DIV = 1000000007;
	ll fun(int n, int l, int r) {
		if (l == 0 || r == 0) return 0;
		if (n == 1) {
			if (l == 1 && r == 1) return 1;
			else return 0;
		}
		ll& ret = dp[n][l][r];
		if (ret != -1) return ret;
		
		ret = 0;
		ret += fun(n - 1, l - 1, r);
		ret += fun(n - 1, l, r - 1);
		ret += fun(n - 1, l, r) * (n - 2);
		ret %= DIV;

		return ret;
	}

	int main() {
		ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
		int N, L, R;
		memset(dp, -1, sizeof(dp));
		cin >> N >> L >> R;
		cout << fun(N, L, R) << endl;
	}