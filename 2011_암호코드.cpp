#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[5001];
unsigned long long dp[5001][2];
int len;
int DIV = 1000000;
unsigned long long fuc(int now_index, int prev_data, bool prev_used) {
	int second;
	if (prev_used) second = 0;
	else second = 1;

	if (dp[now_index][second] != -1) return dp[now_index][second];

	if (!prev_used) {
		if (prev_data * 10 + arr[now_index] < 0 || prev_data * 10 + arr[now_index] > 26) return 0;
		else {
			if (now_index == len - 1) return 1;
			dp[now_index][second] = fuc(now_index + 1, arr[now_index], true);
			return dp[now_index][second] % DIV;
		}
	}
	else {
		if (arr[now_index] == 0) return 0;

		if (now_index == len - 1) return 1;
		dp[now_index][second] = fuc(now_index + 1, arr[now_index], true) + fuc(now_index + 1, arr[now_index], false);
		return dp[now_index][second] % DIV;
	}

}

int main() {
	string str;
	cin >> str;
	len = str.size();
	for (int i = 0; i < len; i++) {
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	for (int i = 0; i < len; i++) {
		int tmp = (int)str.at(i) - 48;
		arr[i] = tmp;
	}
	cout << fuc(0, -100, true) % DIV + fuc(0, -100, false) % DIV << endl;
}