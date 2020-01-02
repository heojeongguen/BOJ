#include <iostream>
#include <algorithm>
using namespace std;

// ���� �迭 ���� ���� �� �����ٺ���
// �� �̺й����� Ǯ��� �ϴ��� �� �� ����
// 0 ~ N * N �� ���ĵ� �迭���� N*N/2 ��° ���� �迭�� ��� ����


int main() {
	unsigned long long N, K;
	unsigned long long ans;
	cin >> N >> K;
	unsigned long long MIN = 0;
	unsigned long long MAX = N * N;
	while (MIN <= MAX) {
		unsigned long long MID = (MIN + MAX) / 2;
		unsigned long long cnt = 0;
		for (int i = 1; i <= N; i++) {
			cnt += min((unsigned long long)N, MID / i);
		}
		if (cnt == K) {
			// cnt == K ������ ������ �ʴ�����
			// MID��� ���� �ش� index�� ���� �ƴ�,
			// �迭�� index�� ��Ÿ��
			// �׷��� �������� Ž���� �ؾ���.
			ans = MID;
			MAX = MID - 1;
		}
		else if (cnt < K) {
			MIN = MID + 1;
		}
		else {
			ans = MID;
			MAX = MID - 1;
		}
	}
	cout << ans << endl;
}