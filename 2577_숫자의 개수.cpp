#include <iostream>
#include <string>
using namespace std;
int dp[10];
int main() {
	unsigned long long A, B, C;
	cin >> A >> B >> C;
	unsigned long long ret = A * B * C;
	string str = to_string(ret);
	for (int i = 0; i < str.size(); i++) {
		dp[(int)str.at(i) - 48]++;
	}
	for (int i = 0; i <= 9; i++) {
		cout << dp[i] << endl;
	}
}