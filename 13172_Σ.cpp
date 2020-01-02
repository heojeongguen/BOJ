#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// arr[1] = ����� 2^1 = 2 �� 
// arr[2] = ����� 2^2 = 4 ��
unsigned long long arr[60];
unsigned long long DIV = 1000000007;

// ����� x ���� ����
unsigned long long fuc(unsigned long long x) {
	int size = log2(x);
	unsigned long long tmp = 1;
	for (int i = 1; i <= size; i++) {
		tmp *= 2;
	}
	if (pow(2, size) == x && size < 60) {
		return arr[size];
	}
	else if (x == 1) {
		return arr[0];
	}
	else if (x == 0) {
		return 1;
	}

	return ((fuc(tmp) % DIV) * (fuc(x - tmp) % DIV)) % DIV;
}


// �ִ�����
int GCM(unsigned long long x, unsigned long long y)
{
	int n;
	while (1) {
		n = x % y;
		if (n == 0) return y;
		x = y;
		y = n;
	}
}

int main() {
	unsigned long long M, N = 0, S = 0, data1, data2;
	unsigned long long ans = 0;
	cin >> M;
	while (M--) {
		cin >> N >> S;

		// �迭�ʱ�ȭ
		for (int i = 0; i < 60; i++) {
			arr[i] = 0;
		}

		// �ִ������� ���м��� ����� �ش�.
		unsigned long long gcm;
		gcm = GCM(N, S);
		N /= gcm;
		S /= gcm;

		// N�� DIV - 2 ���� ���Ѵ�
		arr[0] = N % DIV;
		for (int i = 1; i < 60; i++) {
			arr[i] = ((arr[i - 1] % DIV)* (arr[i - 1] % DIV)) % DIV;
		}
		ans += (S * fuc(DIV - 2)) % DIV;
	}

	// ���
	cout << ans << endl;
}