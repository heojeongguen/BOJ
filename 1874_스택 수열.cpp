#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cur = 1;
	int n, data;
	vector<int> vec;
	vector<string> ans;
	cin >> n;
	bool can = true;
	for (int i = 0; i < n; i++) {
		cin >> data;
		while (true) {
			if (data >= cur) {
				vec.push_back(cur);
				cur++;
				ans.push_back("+");
			}
			else if (data < cur) {
				if (data == vec.back()) {
					vec.pop_back();
					ans.push_back("-");
					break;
				}
				else {
					cout << "NO\n";
					return 0;
					break;
				}
			}
		}
	}
	for (const auto &x : ans) {
		cout << x << "\n";
	}
}