#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1001];
int dp2[1001];
int arr[1001];
int mmax = 0;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i - 1; j++) {
			if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	for (int i = N; i >= 1; i--) {
		dp2[i] = 1;
		for (int j = N; j >= i + 1; j--) {
			if (arr[i] > arr[j]) dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}
	for (int i = 1; i <= N; i++) {
		mmax = max(mmax, dp[i] + dp2[i] - 1);
	}

	cout << mmax << endl;
}