#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define endl '\n'
typedef long long ll;

int dp[51][250001];
int arr[51];
#define MAX_GAP 250000
int N;

// 함수의 파라미터는 -> dp 배열의 인덱스값 ( 항상 )
// 차이값을 이용한 dp배열 활용
int fun(int n, int gap) {
	if (gap >= MAX_GAP) return -1e9;

	if (n == N) {
		if (gap == 0)
			return 0;
		else
			return -1e9;
	}

	int& ret = dp[n][gap];
	if (ret != -1) return ret;

	ret = fun(n + 1, gap);
	ret = max(ret, fun(n + 1, gap + arr[n]));

	if (arr[n] > gap) {
		ret = max(ret, gap + fun(n + 1, arr[n] - gap));
	}
	else {
		ret = max(ret, arr[n] + fun(n + 1, gap - arr[n]));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int ret = fun(0, 0);
	if (ret == -1e9 || ret == 0) cout << -1 << endl;
	else cout << ret << endl;
}