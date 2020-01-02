#include <iostream>

using namespace std;

bool arr[100][100];

int main() {
	int N;
	int x, y;
	int cnt = 0;
	cin >> N;
	int len = 100;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		int r = len - y - 1;
		int c = x;
		for (int j = r; j > r - 10; j--) {
			for (int z = c; z < c + 10; z++) {
				arr[j][z] = true;
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == true) cnt++;
		}
	}
	cout << cnt << endl;
}