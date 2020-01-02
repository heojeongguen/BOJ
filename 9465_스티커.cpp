#include <iostream>
#include <algorithm>
using namespace std;
int arr[2][100000];
int main() {
	int T, N, data,ans;
	int result_up;
	int result_down;
	int prev_up;
	int prev_down;
	int total;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int arr[2][100000];
		cin >> N;
		total = 0;
		result_up = 0;
		result_down = 0;
		for (int j = 0; j < 2; j++) {
			for (int z = 0; z < N; z++) {
				cin >> data;
				total += data;
				arr[j][z] = data;
			}
		}
		for (int j = 0; j < N; j++) {
			if (j == 0) {
				result_up = arr[0][j];
				result_down = arr[1][j];
			}
			else if (j == 1) {
				int temp = result_up;
				result_up = result_down + arr[0][j];
				result_down = temp + arr[1][j];
			}
			else {
				int temp = result_up;
				prev_down = result_up - arr[0][j - 1];
				prev_up = result_down - arr[1][j - 1];
				result_up = max(result_down + arr[0][j], prev_down + arr[0][j]);
				result_down = max(temp + arr[1][j], prev_up + arr[1][j]);
			}
		}
		cout << max(result_up, result_down) << endl;
	}
}