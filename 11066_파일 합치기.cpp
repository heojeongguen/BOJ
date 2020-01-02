#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
// dp���̺� ���� �ü� ���� �ִ밪�� ���� define ��
#define INF 0x7fffffff/2 
using namespace std;
int arr[501];
int dp[501][501];
int sum[501];

// s(start) ,e(end)
int fuc(int s, int e) {
	// start == end : �ڱ� �ڽŰ� ��ġ�°��� 0
	if (s >= e) return 0;

	// �̹� ���̺��� ä�����ִ� ���
	if (dp[s][e] != -1) return dp[s][e];

	// e�� s�� 1���� �ڽŰ� ������ ��ħ
	if (e == s + 1) return arr[s] + arr[e];

	// �ִ밪���� ����
	dp[s][e] = INF;

	// ������� �� 4���� �η��� �ְ� ó�� �Լ� ȣ���
	// (1)(2,3,4) , (1, 2)(3, 4) , (1, 2 ,3)(4) ��ȣ��
	// (1)(2,3,4)�ϰ�� (1) -> 0, (2,3,4) -> (2)(3,4) or (2,3)(4)
	// �����ݺ��ϸ鼭 dp[s][e]�� �ּڰ����� ����ؼ� ��ü��
	for (int i = s; i <= e; i++) {
		// (1)(2,3,4) ��� 4���� �η��� ��� ��ġ�� ����̹Ƿ� sum[4]�� fuc(2,3,4)�� �� ���� tmp���� ��.
		int tmp = fuc(s, i) + fuc(i + 1, e) + sum[e] - sum[s - 1];
		// �� �ݺ����� �ּڰ����� ��ü.
		dp[s][e] = min(dp[s][e], tmp);
	}
	// �������� ��γ������� ����
	return dp[s][e];
}


int main() {
	int T, N, data, ans, cur, mean;
	cin >> T;
	while(T--){
		cin >> N;

		// dp���̺�, sum�迭 �ʱ�ȭ
		for (int i = 0; i <= 501; i++) {
			for (int j = 0; j <= 501; j++) {
				dp[i][j] = -1;
			}
			sum[i] = 0;
		}

		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			// sum[i] = arr[1] ~ arr[N] ������ ����
			sum[i] = sum[i - 1] + arr[i];
		}
		

		cout << fuc(1, N) << endl;

	}
	return 0;
}