#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	string input;
	int ans = 0;
	cin >> str >> input;
	for (int i = 0; i + input.size() <= str.size(); i++) {
		bool flag = true;
		for (int j = 0; j < input.size(); j++) {
			if (input[j] != str[j + i]) {
				flag = false;
				break;
			}
		}
		if (flag) ans++;
	}
	cout << ans << endl;
}