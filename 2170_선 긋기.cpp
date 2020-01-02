#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

typedef pair<int, int> pii;
vector<pii> vec;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		if (b < a) {
			int t = b;
			b = a;
			a = t;
		}
		vec.push_back({ a,b });
	}
	int e = -(1e9+1);
	int ans = 0;
	sort(vec.begin(), vec.end());
	for (int i = 0; i < N; i++) {
		if (e == -(1e9 + 1)) {
			e = vec[i].second;
			ans += e - vec[i].first;
		}

		if (vec[i].first < e) {
			int diff = vec[i].second - e;
			ans += (diff > 0) ? diff : 0;
			e = max(e,vec[i].second);
		}
		else if (vec[i].first >= e) {
			ans += vec[i].second - vec[i].first;
			e = vec[i].second;
		}
	}
	cout << ans << "\n";
}