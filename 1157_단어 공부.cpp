#include <iostream>
#include <string>
using namespace std;
int dp[123];
int main() {
	string str;
	char ans;
	bool dup = false;
	int Max = 0;
	int prevMax = 0;
	cin >> str;
	int MaxChar = 0;
	for (int i = 0; i < str.size(); i++) {
		int index = (int)str.at(i);
		if (index > 90) {
			index -= 32;
		}
		dp[index]++;
		if (dp[index] > Max) {
			Max = dp[index];
			MaxChar = (char)index;
			dup = false;
		}
		else if (dp[index] == Max) {
			dup = true;
		}
	}
	if (dup) {
		ans = '?';
	}
	else {
		ans = MaxChar;
	}
	cout << ans << endl;
}