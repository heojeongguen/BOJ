#include <iostream>

using namespace std;
int arr[15][15];
int fuc(int k, int n) {
	if (k == 0) {
		return n;
	}
	if (arr[k][n] != 0) return arr[k][n];

	int ret = 0;

	for (int i = n ; i >= 1; i--) {
		ret += fuc(k-1, i);
	}
	arr[k][n] = ret;
	return ret;
}

int main() {
	int T, K, N;
	cin >> T;
	while (T--) {
		for (int i = 0; i < 15; i++) {
			for (int j = 0;j < 15; j++) {
				arr[i][j] = 0;
			}
		}
		cin >> K >> N;
		cout << fuc(K, N) << endl;
	}
	
}