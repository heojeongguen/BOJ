#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// B[i][j] = median(A[i+x][j+y]), 
int arr[31][31];
int ans[31][31];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int R, C, K, W;
	cin >> R >> C >> K >> W;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
	vector<int> vec;
	for (int i = 0; i <= R - W; i++) {
		for (int j = 0; j <= C - W; j++) {
			vec.clear();
			for (int x = i; x < i + W; x++) {
				for (int y = j; y < j + W; y++) {
					vec.push_back(arr[x][y]);
				}
			}
			sort(vec.begin(), vec.end());
			ans[i][j] = vec[vec.size() / 2];
		}
	}
	for (int i = 0; i <= R - W; i++) {
		for (int j = 0; j <= C - W; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}