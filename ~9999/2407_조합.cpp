#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
string dp[101][101];
unsigned long long fac(unsigned long long x) {
	unsigned long long ans = 1;
	for (int i = x; i >= 1; i--) {
		ans = (ans * i);
	}
	return ans;
}


int main() {
	unsigned long long m ,n;
	string str;
	cin >> n >> m;
	dp[1][0] = "1";
	dp[1][1] = "1";
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = "1";
			}
			else if (j == i) {
				dp[i][j] = "1";
			}
			else {
				int gap = 0;
				bool left = false;
				if( dp[i - 1][j - 1].size() == dp[i-1][j].size()){
					gap = 0;
				}
				else if (dp[i - 1][j - 1].size() > dp[i - 1][j].size()) {
					gap = dp[i - 1][j - 1].size() - dp[i - 1][j].size();
					gap = abs(gap);
					left = true;
				}
				else {
					gap = dp[i - 1][j - 1].size() - dp[i - 1][j].size();
					gap = abs(gap);
					left = false;
				}
				while (gap--) {
					if (left) {
						dp[i - 1][j].insert(0, "0");
					}
					else {
						dp[i - 1][j-1].insert(0, "0");
					}
				}

				bool up = false;
				str = "";
				int temp = 0;

				for (int z = dp[i-1][j - 1].size() - 1; z >= 0; z--) {
					int temp = (int)dp[i - 1][j - 1].at(z) - 48 + (int)dp[i - 1][j].at(z) - 48;
					if (up) {
						temp++;
					}

					if (temp >= 10) {
						up = true;
					}
					else {
						up = false;
					}
					temp = temp % 10;
					str.push_back((char)(temp + 48));
				}
				if (up) {
					str.push_back('1');
				}
				reverse(str.begin(), str.end());
				dp[i][j] = str;
			}

		}
	}
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 0; j <= i; j++) {
	//		for (const auto & x : dp[i][j]) {
	//			cout << x;
	//		}
	//		cout << " ";
	//	}
	//	cout << endl;
	//}
	bool first = false;
	for (const auto & x : dp[n][m]) {
		if (first) {
			cout << x;
		}
		else {
			if (0 != (int)x - 48) {
				first = true;
				cout << x;
			}
		}
	}
}