#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, D;
unsigned long long arr[1001];
unsigned long long dp[1001];
unsigned long long mmax;
int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		dp[i] = arr[i];
		for (int j = 1; j <= i - 1; j++) {
			if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + arr[i]);
		}
		mmax = max(mmax, dp[i]);
	}
	cout << mmax << endl;
}