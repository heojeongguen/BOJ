#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int t ,n;
	string str;
	string prev_str;
	string cur_str;
	vector<string> vec;
	cin >> t;
	while (t--) {
		string tag = "YES";
		vec.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> str;
			vec.push_back(str);
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size(); i++) {
			if (i == 0) prev_str = vec[0];
			else {
				if (prev_str == vec[i].substr(0, prev_str.size())) {
					tag = "NO";
					break;
				}
				else {
					prev_str = vec[i];
				}
			}
		}
		cout << tag << endl;
	}
}