#include <iostream>
#include <iostream>
using namespace std;

unsigned long long dp[1001][10];
int N;
// dp[index][num] : index ���̸� ���� num���� ������ ���� ����
int fuc(int index, int num) {
	// 0������ ���� ����
	if (index <= 0) return 0;

	// 0�̸��� ���� ������ ���� ����
	if (num < 0) return 0;

	// �̹� ä���� ���̺��̸� Ż��
	if (dp[index][num] != 0) return dp[index][num];

	// dp[1][?] = 1 ��, dp[1][0], dp[1][1], dp[1][2] , dp[1][3] , ... , dp[1][9] �� ���� 10 �̵ȴ�. -> ���ڸ� ���� ���� 10
	if (index == 1) return 1;

	// dp ���̺��� ä�������� ������ 10007 �� div ���ش�.
	for (int i = 0; i <= num; i++) {
		dp[index][num] += fuc(index - 1, i);
		dp[index][num] %= 10007;
	}
	return dp[index][num] % 10007;
}

int main() {
	int N;
	unsigned long long ans = 0;
	cin >> N;
	// N�ڸ����� 0,1,2...9 �γ����� ���� ans�� �����ش�
	// �������� 10007�� ������ �ش�.
	for (int i = 0; i <= 9; i++) {
		ans += fuc(N, i);
		ans %= 10007;
	}
	cout << ans  << endl;
	return 0;
}