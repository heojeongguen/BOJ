#include <iostream>
using namespace std;

int arr[301][301];
int sum[301][301];
int main() {
	int R, C, Q;
	int r1, c1, r2, c2;
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
			sum[i][j] = sum[i][j-1] + arr[i][j];
		}
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int ret = 0;
		cin >> r1 >> c1 >> r2 >> c2;
		for (int j = r1; j <= r2; j++) {
			ret += sum[j][c2] - sum[j][c1 - 1];
		}
		cout << ret << endl;
	}
}