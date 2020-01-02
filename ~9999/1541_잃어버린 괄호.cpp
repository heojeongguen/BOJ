#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
vector<string> s;
int main() {
	string str;
	cin >> str;
	int tmp = 0;
	int cnt = 0;
	int prev = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str.at(i) == '-') {
			s.push_back(str.substr(prev, cnt));
			prev = i + 1;
			cnt = 0;
			continue;
		}
	
		cnt++;
		if (i == str.size() - 1) {
			s.push_back(str.substr(prev, cnt));
		}
	}
	//for (const auto &x : s) {
	//	cout << x << endl;
	//}
	int ret = 0;
	vector<int > ans;
	for (const auto &x : s) {
		tmp = 0;
		cnt = 0;
		ret = 0;
		for (int i = x.size() - 1; i >= 0; i--) {
			if (x[i] == '+') {
				ret += tmp;
				tmp = 0;
				cnt = 0;
			}
			else {
				tmp += ((int)x[i] - 48) * pow(10, cnt);
				cnt++;
			}
		}
		ret += tmp;
		ans.push_back(ret);
	}
	//for (const auto &x : ans) {
	//	cout << x << endl;
	//}
	for (int i = 0; i < ans.size(); i++) {
		if (i == 0) ret = ans[0];
		else {
			ret -= ans[i];
		}
	}
	cout << ret << endl;
}