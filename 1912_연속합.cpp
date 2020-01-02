#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long arr[100001];
unsigned long long dp[100001][2];
int N;
unsigned long long MIN = -99999999;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	unsigned long long MAX;
	unsigned long long cur = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (i == 1) MAX = arr[i];
		else MAX = max(MAX, arr[i]);
	}
	unsigned long long ret = -12345;
	unsigned long long psum = 0;

	for (int i = 1; i <= N; i++)
	{
		psum = max(psum, (unsigned long long)0) + arr[i];
		ret = max(psum, ret);
	}
	cout << max(MAX,ret) << endl;
}