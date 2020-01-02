#include <iostream>
#include <string>
using namespace std;

string check(string s) {
	bool moem = false;
	int moemCnt = 0;
	int jaumCnt = 0;
	bool db = false;
	string ret = "acceptable";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			moem = true;
			moemCnt++;
			jaumCnt = 0;
			if (moemCnt == 3) {
				ret = "not acceptable";
				break;
			}
			if (s[i] != 'o' && s[i] != 'e' && i > 0) {
				if (s[i] == s[i - 1]) {
					ret = "not acceptable";
					break;
				}
			}
		}
		else {
			moemCnt = 0;
			jaumCnt++;
			if (jaumCnt == 3) {
				ret = "not acceptable";
				break;
			}
			if (i > 0) {
				if (s[i] == s[i - 1]) {
					ret = "not acceptable";
					break;
				}
			}
		}
	}
	if(!moem) 	ret = "not acceptable";
	return "<" + s + "> is " + ret + ".\n";
}

int main() {
	string str;

	while (true) {
		cin >> str;
		if (str == "end") break;
		cout << check(str);
	}
}