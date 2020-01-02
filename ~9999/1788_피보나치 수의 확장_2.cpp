#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<unsigned long long> > matrix;

matrix operator*(const matrix & a, const matrix & b) {
	int size = a.size();
	matrix c(size);
	for (int i = 0; i < size; i++) {
		c[i] = vector<unsigned long long>(size);
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			unsigned long long tmp = 0;
			for (int k = 0; k < size; k++) {
				tmp += a[i][k] * b[k][j];
			}
			c[i][j] = tmp;
		}
	}
	return c;
}

unsigned long long pow(int n, int e) {
	int ret = 1;
	int tmp = n;
	while (e > 0) {
		if (e % 2 == 1) ret *= tmp;
		tmp = tmp * tmp;
		e /= 2;
	}
	return ret;
}

int main() {
	int N;
	cin >> N;

	matrix a = { {1,0},{0,1} };
	matrix b = { {1,1}, {1,0} };

	while (N > 0) {
		if (N % 2 == 1) {
			a = a * b;
		}
		b = b * b;
		N /= 2;
	}

	cout << a[0][1] << endl;

	cout << pow(2, 10) << endl;
}