#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
char dp[1000][1000];
int main() {
	int index_up = 0;
	int index_down = 0;
	int temp_result = 0;
	bool flag[1000][1000] = { false, };
	bool find = true;
	string str1;
	string str2;
	int ans = 0;


	cin >> str1 >> str2;
	for (int j = 0; j < str1.size(); j++) {
		dp[0][j] = str1.at(j);
	}
	for (int j = 0; j < str2.size(); j++) {
		dp[1][j] = str2.at(j);
	}


	while (find) {
		temp_result = 0;
		index_down = 0;
		find = false;
		for (int i = 0; i < str1.size(); i++) {
			for (int j = index_down; j < str2.size(); j++) {
				if (dp[0][i] == dp[1][j]) {
					if (flag[i][j] == true) {
						break;
					}
					else {
						find = true;
						flag[i][j] = true;
						index_down = j + 1;
						temp_result++;
						break;
					}
				}
			}
		}
		if (find == false) {
			break;
		}
		else {
			ans = max(ans, temp_result);
		}
	}
	flag[1000][1000] = { false, };
	find = true;
	while (find) {
		index_up = 0;
		temp_result = 0;
		find = false;
		for (int i = 0; i < str2.size(); i++) {
			for (int j = index_up; j < str1.size(); j++) {
				if (dp[1][i] == dp[0][j]) {
					if (flag[i][j] == true) {
						break;
					}else{
						index_up = j + 1;
						temp_result++;
						find = true;
						flag[i][j] = true;
						break;
					}
				}
			}
		}
		if (find == false) {
			break;
		}
		else {
			ans = max(ans, temp_result);
		}
	}
	cout << ans << endl;
}