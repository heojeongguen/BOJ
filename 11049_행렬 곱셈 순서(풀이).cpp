#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;


// 파일 합치기와 비슷한 유형
// 구간의 합의 최소를 구하는 방법 by DP
// dp[ x ][ y ] : x~y까지 구간의 최솟값.

int dp[501][501];
pair<int, int> arr[501];
int N;

// x ~ y : 의 최소값을 리턴

int fuc(int x, int y) {
	// 예외처리
	if (x == y)
		return 0;

	int& ref = dp[x][y];

	// 성능향상
	if (ref != -1)
		return ref;

	// 최솟값을 구한다? ret을 말도안되는 최대로놓고 값을 구해나간다.
	int mm = INT_MAX;

	// x ~ k 와 k + 1 ~ y 까지의 최소값을 곱하는 식 : (x .. k) * ((k + 1).. y);
	// x.first * k.second* y * second 가 나오게됨.
	for (int k = x; k < y; ++k)
		mm = min(mm, fuc(x, k) + fuc(k + 1, y) + arr[x].first * arr[k].second * arr[y].second);

	return ref = mm;
}

int main() {
	int d1, d2;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> d1 >> d2;
		arr[i] = { d1, d2 };
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = -1;
		}
	}

	cout << fuc(1, N) << endl;
}