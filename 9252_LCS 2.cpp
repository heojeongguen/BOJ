#include <iostream>
#include <string>
using namespace std;
pair<int, string> dp[1001][1001];
int main() {
	string str1, str2, tmp;
	cin >> str1 >> str2;
	if (str1.size() < str2.size()) {
		tmp = str1;
		str1 = str2;
		str2 = tmp;
	}
	for (int i = 0; i <= str2.size(); i++) {
		for (int j = 0; j <= str1.size(); j++) {
			dp[i][j].first = 0;
			dp[i][j].second = "";
		}
	}
	for (int i = 0; i < str2.size(); i++) {
		for (int j = 0; j < str1.size(); j++) {
			if (str2.at(i) == str1.at(j)) {
				dp[i + 1][j + 1].first = dp[i][j].first + 1;
				dp[i + 1][j+1].second = dp[i ][j].second;
				dp[i + 1][j + 1].second.push_back(str2.at(i));
			}
			else {
				if (dp[i + 1][j].first > dp[i][j + 1].first) {
					dp[i + 1][j + 1].first = dp[i + 1][j].first;
					dp[i + 1][j + 1].second = dp[i + 1][j].second;
				}
				else {
					dp[i + 1][j + 1].first = dp[i][j+1].first;
					dp[i + 1][j + 1].second = dp[i][j+1].second;
				}
			}
		}
	}
	cout << dp[str2.size()][str1.size()].first << endl;
	cout << dp[str2.size()][str1.size()].second << endl;
}