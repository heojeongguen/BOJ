#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[2001];
int dp[2001][2001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, D, Q, from, to;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> from >> to;
		from = min(from, to);
		to = max(from, to);
		if (from == to) {
			dp[from][to] = 1;
			if (dp[from][to] == 1) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else {
			if ((from - to) % 2 == 0) {
				int mid = (from + to) / 2;
				for (int j = 1; j + mid <= to, mid - j >=0; j++) {
				
					if (dp[mid - j][mid + j] == -1 || dp[mid - j][mid + j] == 1) break;

					if (arr[mid - j] == arr[mid + j]) {
						dp[mid - j][mid + j] = 1;
					}
					else {
						dp[mid - j][mid + j] = -1;
						break;
					}
				}
				if (dp[from][to] == 1) {
					cout << 1 << "\n";
				}
				else {
					cout << 0 << "\n";
				}
			}
			else {
				int left = (to + from) / 2;
				int jump = 1;
				for (int j = left; j >= from , j + jump <= N; j--) {
					if ( dp[j][j + jump] == 1 || dp[j][j + jump] == -1 ) break;
					if ( arr[j] == arr[j + jump] ) dp[j][j + jump] = 1;
					else {
						dp[j][j + jump] = -1;
						break;
					}
					jump += 2;
				}
				if (dp[from][to] == 1) {
					cout << 1 << "\n";
				}
				else {
					cout << 0 << "\n";
				}
			}
		}

	}
}