#include <iostream>
#include <vector>

using namespace std;

// MOD ��
unsigned long long DIV = 1000000007;

// ���߹迭 ���¸� ���� Ÿ�� ����
typedef vector<vector<unsigned long long>> matrix;


// �ϱ� ! ��Ŭ���� ȣ����� ����� GCD (�ִ�����) ���ϱ�
unsigned long long GCD(unsigned long long a, unsigned long long b) {
	if (b == 0) return a;
	return GCD(b, a % b);
}

// ���� ������ marix ������ operator �Լ�
matrix operator * (const matrix & a, const matrix & b) {
	int n = a.size();
	matrix c(n, vector<unsigned long long>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= DIV;
		}
	}
	return c;
}

int main() {
	unsigned long long n, m;
	unsigned long long gcd;
	cin >> n >> m;
	if (n < m) {
		gcd = GCD(n, m);
	}
	else {
		gcd = GCD(m, n);
	}

	// ��İ��� ���� matrix
	// ���� : ans
	// �������� ��� a
	// F(n) = a^n
	matrix ans = { {1,0},{0,1} };
	matrix a = { {1,1},{1,0} };

	// pow�� ���Ҷ��� ���� �ƶ�
	while (gcd > 0) {
		if (gcd % 2 == 1) {
			ans = ans * a;
		}
		a = a * a;
		gcd /= 2;
	}

	// [0][0] : F(n+1);
	// [0][1] : F(n);
	// [1][0] : F(n);
	// [1][1] : F(n-1);
	cout << ans[0][1] << endl;

	return 0;
}