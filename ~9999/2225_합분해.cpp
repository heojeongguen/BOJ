#include <iostream>

using namespace std;

int N, K;
unsigned long long dp[201][201];
unsigned long long DIV = 1000000000;

int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		dp[i][1] = 1;
	}
	for (int i = 0; i <= K; i++) {
		dp[0][i] = 1;
	}

	for (int i = 2; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			for (int z = 0; z <= j; z++) {
				dp[j][i] += dp[z][i-1];
				dp[j][i] %= DIV;
			}
		}
	}
	// È®ÀÎ¿ë
	//for (int i = 1; i <= K; i++) {
	//	for (int j = 0; j <= N; j++) {
	//		cout << dp[j][i] << " ";
	//	}
	//	cout << endl;
	//}
	cout << dp[N][K] % DIV << endl;
}