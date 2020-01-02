#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> vec;
int dp[1001];
int main() {
	int data;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> data;
		vec.push_back(data);
	}	


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i - j] + vec.at(j-1), dp[i]);
		}
	}
	cout << dp[N] << endl;
}