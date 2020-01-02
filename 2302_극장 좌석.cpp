#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, D;
bool vip[41];
int arr[41];
int dp[41];
vector<int> vec;



int main() {

	cin >> N;
	cin >> M;

	fill(vip, vip + 41, false);

	for (int i = 0; i < M; i++) {
		cin >> D;
		vip[D] = true;
		
	}

	int cnt = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[0] = 1;

	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int ans = 1;

	for (int i = 1; i <= N; i++) {
		if (vip[i] == false) {
			cnt++;
		}else {
			ans *= dp[cnt];
			cnt = 0;
		}
	}
	cout << ans * dp[cnt ]<< endl;
}