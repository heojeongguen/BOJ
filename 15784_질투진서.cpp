#include <iostream>
using namespace std;
int arr[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, r, c;
	cin >> N >> r >> c;
	r--;
	c--;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	bool find = false;

	for (int i = 0; i < N; i++) {
		if (i == c) continue;
		else if (arr[r][i] > arr[r][c]) find = true;
	}

	for (int i = 0; i < N; i++) {
		if (i == r) continue;
		else if (arr[i][c] > arr[r][c]) find = true;
	}

	if (find) cout << "ANGRY" << endl;
	else cout << "HAPPY" << endl;

	return 0;
}