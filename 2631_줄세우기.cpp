#include <iostream>
#include <algorithm>
using namespace std;

int arr[201];
int dp[201];

int main() {
	int N, D, cnt = 0, mmax = 0;
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i - 1; j++) {
			if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
		mmax = max(mmax, dp[i]);
	}
	cout << N - mmax << endl;
}