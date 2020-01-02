#include <iostream>

using namespace std;

// ���Ϸ� �� �Լ��� �̿��� N �� n������ �ڿ����� ���μ��� ���� ���ϱ�


int main() {
	unsigned long long n;
	cin >> n;
	unsigned long long ans = n;

	// ��� = n(1-1/P1)(1-1/P2)....(1-1/Pend);
	for (unsigned long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				// ���� ������ n�� i�� ������������
				// ���Թ����� ��������
				// �Ȱ��� ���� Ž���ϴ� ��츦 �����ϱ� �����̴�.
				n /= i;
			}
			// ��� *= (1-1/P);
			ans *= (1.0 - (1.0 / i));
		}
	}
	// ���������� �μ��� ���μ��̰�, ���ѹ����� ���Ͽ�
	// Ž������ �ʾ������� ����̴�.
	if (n > 1) {
		ans *= (1.0 - (1.0 / n));
	}
	cout << ans << endl;
}