#include <iostream>
#include <string>
using namespace std;

int main() {
	string str[5];
	string ans;
	int len[5];
	for (int i = 0; i < 5; i++) {
		cin >> str[i];
		len[i] = str[i].size();
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (len[j] < i) continue;
			else {
				ans.push_back(str[j][i]);
			}
		}
	}
	for (const auto & x : ans) {
		if ((int)x != 0) cout << x;
	}
	
}