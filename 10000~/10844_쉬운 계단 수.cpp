#include <iostream>

using namespace std;


unsigned long long dp[101][10];

// dp[index][num] : index������ num���� ������ ��
unsigned long long fuc(int index, int num) {
	// ���̴� 1 �̻�
	if (index <= 0) return 0;

	// ���ڹ����� 0 ~ 9
	if (num < 0 || num > 9) return 0;

	// �̹� ä���� ���̺� Ż��
	if (dp[index][num] != 0) return dp[index][num];

	// ���ڸ� �� �̸鼭 0�� ���� ���� �� dp[1][0] = 0 �̴�.
	if (index == 1) {
		if(num != 0) 	return 1;
		else return 0;
	}

	// index ������ num ���� ������ ���� index-1 �� ������ ������ 1 ũ�ų� ���� ���̴�.
	// �� ) dp[2][2] : 2������ 2�� �����¼�
	// dp[2][2] = dp[1][1] + dp[1][3] -> ���ڸ��� 1 �� 3 ������ 2�� ���� ��� -> 12 32 
	dp[index][num] = (fuc(index - 1, num - 1) + fuc(index - 1, num + 1)) % 1000000000;

	return dp[index][num] % 1000000000;

}


int main() {
	int N;
	unsigned long long ans = 0;
	cin >> N;
	for (int i = 0; i <= 9; i++) {
		ans += fuc(N, i);
		ans %= 1000000000;
	}
	cout << ans << endl;
	return  0;
}