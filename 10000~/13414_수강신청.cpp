#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
#include <deque>

using namespace std;
set<string> m;
set<string>::iterator iter;
vector<string> vec;
deque<string> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	string s;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> s;
		vec.push_back(s);

	}

	for (int i = vec.size() - 1; i >= 0; i--) {
		iter = m.find(vec[i]);

		if (iter == m.end()) {
			m.insert(vec[i]);
			ans.push_front(vec[i]);
		}
		else {
			continue;
		}
	}

	for (const auto & x : ans) {
		if (N == 0) break;
		cout << x << "\n";
		N--;
	}
}