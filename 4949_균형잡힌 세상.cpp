#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string str , ans;
	vector<char> vec;
	while (true) {
		ans = "yes";
		vec.clear();
		getline(cin, str);
		if (str == ".") {
			break;
		}
		for (int i = 0; i < str.size(); i++) {
			if (str.at(i) == '(') {
				vec.push_back('(');
			}
			else if (str.at(i) == '[') {
				vec.push_back('[');
			}
			else if (str.at(i) == ')') {
				if (vec.size() == 0 || vec.back() != '(') {
					ans = "no";
					break;
				}
				else {
					vec.pop_back();
				}
			}
			else if (str.at(i) == ']') {
				if (vec.size() == 0 || vec.back() != '[') {
					ans = "no";
					break;
				}
				else {
					vec.pop_back();
				}
			}
		}
		if (ans == "no") {
			ans = "no";
		}
		else {
			if (vec.size() == 0) {
				ans = "yes";
			}
			else {
				ans = "no";
			}
		}
		cout << ans << endl;
	}
}