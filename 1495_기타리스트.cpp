#include <iostream>
#include <algorithm>
using namespace std;

// ����
int v[101];

// dp���̺�
int dp[101][1001];

// ans�� �ʱⰪ -1�� ����
// ( ans�� ��� ���⵵ ����������� : �߰��� ��� ���� �������� �������� ���ϱ⶧���� -1�� ��µ�)
int N, M, S, ans = -1;

// c(count) : c��° ��( index ������ ���� )
// b(before) : ������� ����(c) ������ �Ѿ������ ����
int fuc(int c, int b) {
	// N��° ���� �ִ�
	if (c > N) return 0;

	// 0���� �۾����� ���
	if (b < 0) return 0;

	// M���� Ŀ���� ���
	if (b > M) return 0;

	// ������� �������� ��
	// ���ǿ� ���� �Ѵٸ� ans�� ��ü
	if (c == N) {
		if (b + v[c] <= M && b + v[c] >= 0) {
			ans = max(b + v[c], ans);
			return b + v[c];
		}
		if (b - v[c] >= 0 && b - v[c] <= M) {
			ans = max(ans, b - v[c]);
			return b - v[c];
		}
		// �Ǽ� ! : -1���� �������ְ� �Ǹ� �̹� �湮�� ���̺��� �ʱ�ȭ ���ѹ����� ���� �Ǳ⶧���� ,�ݺ� Ƚ���� ��û���� ��������.
		return 0;
	}

	if (dp[c][b] != -1) return dp[c][b];
	
	
	dp[c][b] = max(fuc(c + 1, b + v[c]), fuc(c + 1, b - v[c]));

	return dp[c][b];

}

int main() {
	int data;
	cin >> N >> S >> M;

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 1000; j++) {
			dp[i][j] = -1;
		}
	}

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	fuc(1, S);
	cout << ans << endl;
}