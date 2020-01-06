#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define endl '\n'
typedef long long ll;

int dp[2501];
bool check[2501][2501];
int N;
string input;

int fun(int s) {
	if (s < 0) return 0; // 탈출조건 설정
	if (dp[s] != -1) return dp[s]; // 계산완료 했을 경우
	dp[s] = 1e9;
	for (int i = s; i >= 0; i--) {
		if (check[i][s]) {
			dp[s] = min(dp[s], 1 + fun(i - 1)); // 되는경우의 수만 탐색
		}
	}
	return dp[s];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> input;
	N = input.size();
	for (int i = 0; i < N; i++) {
		check[i][i] = true;
		if (i != N - 1) {
			if (input[i] == input[i + 1]) {
				check[i][i + 1] = true;
				check[i + 1][i] = true;
			}
		}
	}
	for (int i = 2; i < N; i++) {
		for (int j = 0; j + i < N; j++) {
			if (input[j] == input[j + i] && check[j + 1][j + i - 1]) {
				check[j][j + i] = true;
				check[j + i][j] = true;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		dp[i] = -1;
	}
	cout << fun(N-1) << endl;
}