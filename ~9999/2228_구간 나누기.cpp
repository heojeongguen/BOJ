#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define endl '\n'
typedef long long ll;
int N, M;
vector<int> vec;
vector < vector<int> > sum;
vector<vector<int>> dp;

int fun(int now, int m) {
	if (now < 0) {
		if (m == M) return 0;
		else return -1e8;
	}
	if (m > M) return -1e8;
	if (m == M) return 0;

	int& ret = dp[now][m];
	if (ret != -1e9) return ret;
	ret = fun(now - 1, m);

	for (int i = now; i >= 0; i--) {
		ret = max(dp[now][m], sum[i][now] + fun(i - 2, m + 1));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	sum.resize(N);
	dp.resize(N);
	for (int i = 0; i < N; i++) {
		dp[i].resize(M, -1e9);
	}
	for (int i = 0; i < N; i++) {
		sum[i].resize(N);
	}
	for (int i = 0; i < N; i++) {
		int data; cin >> data;
		vec.push_back(data);
		sum[i][i] = data;
	}
	
	for (int i = 1; i < N; i++) {
		for (int j = 0; j + i< N; j++) {
			sum[j+i][j] = sum[j][j + i] = vec[j + i] + sum[j][j + i - 1];
		}
	}
	cout << fun(N - 1,0) << endl;
}