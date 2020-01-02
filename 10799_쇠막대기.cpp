#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int ans = 0;
	string str;
	vector<char> vec;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str.at(i) == ')' ) {
			if (str.at(i - 1) == '(') {
				vec.pop_back();
				ans += vec.size();
			}
			else {
				ans += 1;
				vec.pop_back();
			}
		}
		else {
			vec.push_back('(');
		}
	}
	cout << ans;
}