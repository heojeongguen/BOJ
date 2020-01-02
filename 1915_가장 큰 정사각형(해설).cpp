#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 해설 보고 품
// 2x2 정사각형 박스를 이동시켜서 dp를 조작.
int arr[1001][1001];
int dp[1001][1001];
int mmax = 0;

void fuc(int nowR, int nowC) {
	dp[nowR][nowC] = min({ dp[nowR - 1][nowC], dp[nowR][nowC - 1], dp[nowR - 1][nowC - 1] }) + 1;
	mmax = max(dp[nowR][nowC], mmax);
}

int main() {
	int r, c;
	string str;
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j + 1] = (int)str[j] - 48;
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j] == 1) fuc(i, j);
		}
	}
	cout << mmax * mmax<< endl;
	return 0;
}