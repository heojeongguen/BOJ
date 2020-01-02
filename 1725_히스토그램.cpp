#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	stack<pair<int, int>> st;
	vector<pair<int, int>> vec;
	int n, d, garo, sero;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> d;
		vec.push_back(make_pair(i,d));
	}
	for (int i = 0; i < n; i++) {
		while (!st.empty() && st.top().second > vec[i].second) {
			pair<int, int> right = st.top(); st.pop();

			if (st.empty()) garo = i;
			else garo = i - st.top().first - 1;

			int sero = right.second;
			ans = max(ans, garo * sero);
		}
		st.push(vec[i]);
	}
	while (!st.empty()) {
		pair<int, int> right = st.top(); st.pop();

		if (st.empty()) garo = n;
		else garo = n - st.top().first - 1;

		int sero = right.second;
		ans = max(ans, garo * sero);
	}
	cout << ans << "\n";
	return 0;
}