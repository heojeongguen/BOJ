#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

int N, M;
set<string> s;
set<string>::iterator iter;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int order, a, b;
	vector<string> vec(N,"00000000000000000000");
	for (int i = 0; i < M; i++) {
		cin >> order;
		if (order == 1) {
			cin >> a >> b;
			vec[a-1][b - 1] = '1';
		}
		else if (order == 2) {
			cin >> a >> b;
			vec[a-1][b - 1] = '0';
		}
		else if (order == 3) {
			cin >> a;
			vec[a-1].pop_back();
			vec[a-1] = '0' + vec[a - 1];
		}
		else if (order == 4) {
			cin >> a;
			reverse(vec[a-1].begin(), vec[a - 1].end());
			vec[a-1].pop_back();
			vec[a-1] = '0' + vec[a - 1];
			reverse(vec[a - 1].begin(), vec[a - 1].end());
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		iter = s.find(vec[i]);
		if (iter == s.end()) {
			ans++;
			s.insert(vec[i]);
		}
	}
	cout << ans << endl;
}