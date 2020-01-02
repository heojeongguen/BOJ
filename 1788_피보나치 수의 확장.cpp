#include <iostream>
#include <vector>
using namespace std;
unsigned long long DIV = 1000000000;
typedef vector<vector<unsigned long long>> matrix;
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
	int N, origin; cin >> N; origin = N;
	if (N < 0) N *= -1;
	matrix ans = { {1,0},{0,1} };
	matrix a = { {1,1},{1,0} };
	// pow¸¦ ±¸ÇÒ¶§¶û °°Àº ¸Æ¶ô
	while (N > 0) {
		if (N % 2 == 1) {
			ans = ans * a;
		}
		a = a * a;
		N /= 2;
	}
	// [0][0] : F(n+1) ,[0][1] : F(n), [1][0] : F(n),  [1][1] : F(n-1);
}