#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int dp[16];
int N, D1, D2;
vector<pair<int, int>> vec;
int fuc(int now) {
	if (dp[now] != -1) return dp[now];

	if (now >= N) return 0;

	if (now + vec[now].first > N) return fuc(now + 1);

	dp[now] = max(fuc(now + 1), vec[now].second + fuc(now + vec[now].first));


	return dp[now];
}

int main() {
	cin >> N;

	fill(dp, dp + 15, -1);

	for (int i = 0; i < N; i++) {
		cin >> D1 >> D2;
		vec.push_back(make_pair(D1,D2));
	}
	cout << fuc(0) << endl;
}