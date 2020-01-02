#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	set<string> s;
	vector<string> ans;
	int N, M ,cnt = 0;
	cin >> N >> M;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		s.insert(str);
	}
	for (int j = 0; j < M; j++) {
		cin >> str;
		if (s.count(str) == 1) {
			cnt++;
			ans.push_back(str);
		}
	}
	cout << cnt << endl;
	sort(ans.begin(), ans.end());
	for (const auto & x : ans) {
		cout << x << "\n";
	}
}