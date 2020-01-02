#include <iostream>
#include <algorithm>
using namespace std;
int arr[10001];
int dp[10001][3];

int fuc(int n, bool prev) {
	int index = 1;
	if (prev) {
		 index = 1;
	}
	else {
		 index = 2;
	}
	if (n <= 0) return 0;
	if (dp[n][index] != 0) return dp[n][index];
	
	if (n == 1) {

		return arr[1];
	}
	if (prev) {
		dp[n][index] = max({ fuc(n - 1, false), arr[n] + fuc(n - 2, false) });
	}
	else {
		dp[n][index] = max({ fuc(n - 1, false), arr[n] + fuc(n - 1,true) });
	}
	
	return dp[n][index];
}

int main() {
	int N, data;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	cout << fuc(N, false) << endl;
}