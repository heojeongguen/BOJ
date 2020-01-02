#include <iostream>
#include <limits.h>
#include <algorithm>
#include <cstring>
using namespace std;
int N, T;

// O 가만히
// A 위로 1미터
// B 현재높이만큼 위로
// C아래로 1기능
// T어디로던 텔레포트( 최소한 사용 ) ;
bool arr[101][21];
int dp[101][21][51];
int fuc(int now, int hei, int T) {
	if (hei <= 0 || T < 0 || hei > 20 || now > N) return -1;
	if (!arr[now][hei]) return -1;
	if (now == N) return T;
	if (dp[now][hei][T] != -2) return dp[now][hei][T];
	int ret = -1;
	for (int i = 1; i <= 20; i++) {
		if(i == hei - 1) ret = max ( ret, fuc(now + 1, i, T));
		else if( i == hei + 1) ret = max(ret,fuc(now + 1, i, T));
		else if (i == hei)  ret = max(ret, fuc(now + 1, i, T));
		else if (i == min(20, hei + hei)) ret = max(ret, fuc(now + 1, i, T));
		else  ret = max(ret, fuc(now + 1, i, T-1));
	}
	dp[now][hei][T] = ret;
	return dp[now][hei][T];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 20; j++) {
			for (int z = 0; z <= 50; z++) {
				dp[i][j][z] = -2;
			}
			arr[i][j] = false;
		}
	}
	int cnt;
	int num;
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			cin >> num;
			arr[i + 1][num] = true;
		}
	}
	arr[0][1] = true;
	int ret = fuc(0, 1, T);
	if (ret < 0) cout << -1 << "\n";
	else cout << T - ret << "\n";
}