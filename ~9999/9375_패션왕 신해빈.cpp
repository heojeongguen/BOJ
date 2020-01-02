#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int T, ans = 1;
	vector<pair<string, int>> cloth;
	cin >> T;
	while (T--) {                     
		int N;
		cloth.clear();
		cin >> N;
		ans = 1;
		while (N--) {
			bool find = false;
			string str;
			cin >> str >> str;
			if (cloth.empty()) {
				cloth.push_back(make_pair(str, 1));
			}
			else {
				for (int i = 0; i < cloth.size(); i++) {
					if (cloth.at(i).first == str) {
						find = true;
						cloth.at(i) = { cloth.at(i).first, cloth.at(i).second + 1 };
						break;
					}
				}
				if (!find) {
					cloth.push_back(make_pair(str, 1));
				}
			}
		}

		for (const auto &x : cloth) {
			ans *= x.second + 1;
		}
		cout << ans - 1 << endl;
	}
}