#include <iostream>
#include <vector>

using namespace std;

// MOD 값
unsigned long long DIV = 1000000007;

// 이중배열 형태를 갖는 타입 선언
typedef vector<vector<unsigned long long>> matrix;


// 암기 ! 유클리드 호재법을 사용한 GCD (최대공약수) 구하기
unsigned long long GCD(unsigned long long a, unsigned long long b) {
	if (b == 0) return a;
	return GCD(b, a % b);
}

// 내가 정의한 marix 형태의 operator 함수
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

	// 행렬곱을 위한 matrix
	// 기준 : ans
	// 곱해지는 행렬 a
	// F(n) = a^n
	matrix ans = { {1,0},{0,1} };
	matrix a = { {1,1},{1,0} };

	// pow를 구할때랑 같은 맥락
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