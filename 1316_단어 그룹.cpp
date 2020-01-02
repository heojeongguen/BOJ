#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, ans = 0;
	cin >> T;
	bool dp[123];
	string str;
	while (T--) {
		cin >> str;
		char prev = '*';

		bool suc = true;
		for (int i = 0; i < 123; i++) {
			dp[i] = false;
		}
		for (int i = 0; i < str.size(); i++) {
			if (prev != str.at(i)) {
				if (dp[(int)str.at(i)] == true) {
					suc = false;
					break;
				}
				else {
					dp[(int)str.at(i)] = true;
				}
			}
			prev = str.at(i);
		}
		if (suc) ans++;
	}
	cout << ans << endl;
}