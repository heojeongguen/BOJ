#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;


// ���� ��ġ��� ����� ����
// ������ ���� �ּҸ� ���ϴ� ��� by DP
// dp[ x ][ y ] : x~y���� ������ �ּڰ�.

int dp[501][501];
pair<int, int> arr[501];
int N;

// x ~ y : �� �ּҰ��� ����

int fuc(int x, int y) {
	// ����ó��
	if (x == y)
		return 0;

	int& ref = dp[x][y];

	// �������
	if (ref != -1)
		return ref;

	// �ּڰ��� ���Ѵ�? ret�� �����ȵǴ� �ִ�γ��� ���� ���س�����.
	int mm = INT_MAX;

	// x ~ k �� k + 1 ~ y ������ �ּҰ��� ���ϴ� �� : (x .. k) * ((k + 1).. y);
	// x.first * k.second* y * second �� �����Ե�.
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