#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <deque>
using namespace std;

// str = str2
// str.insert( npos , string )
// str.push_back(char)
// str의 길이가 길어질수록 속도차이가 어마어마 함!

string dp[10001];
int main() {
	int N, len1, len2, tmp;
	int carry;
	string str;
	cin >> N;
	dp[0] = "0";
	dp[1] = "1";
	dp[2] = "1";
	for (int i = 3; i <= N; i++) {
		str = "";
		carry = 0;
		len1 = dp[i - 1].size();
		len2 = dp[i - 2].size();
		if(len1 != len2){
			dp[i-2].push_back('0');
		}
		for (int j = 0; j < len1  ; j++) {
			tmp = (int)dp[i - 1].at(j) - 48 + (int)dp[i - 2].at(j) - 48 + carry;
			str.push_back(((char)tmp % 10) + 48);
			if (tmp >= 10) {
				carry = 1;
			}
			else {
				carry = 0;
			}
		}
		if (carry == 1) {
			str.push_back('1');
		}
		dp[i] = str;
	}
	reverse(dp[N].begin(), dp[N].end());
	cout << dp[N] << endl;
}

