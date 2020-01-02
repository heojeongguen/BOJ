#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------

// #define MAX_N 1001
map<string, vector<string> > m;
map<string, string> A;
map<string, string> B;
map<string, string> visit;

bool fun(string x) {
	visit[x] = true;
	for (int i = 0; i <  m[x].size(); i++) {
		string y = m[x][i];
		cout << " y : " << y << endl;
		if (B.find(y) == B.end() || (visit.find(B[y]) == visit.end()) && fun(B[y])) {
			A[x] = y;
			B[y] = x;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		m.clear();
		int c, d, v; cin >> c >> d >> v;
		for (int i = 0; i < v; i++) {
			string win, lose; cin >> win >> lose;
			m[win].push_back(lose);
		}
		int ans = 0;
		A.clear();
		B.clear();
		for (auto iter = m.begin(); iter != m.end(); iter++) {
			cout << "iter : " << iter->first << endl;
			if (A.find(iter->first) == A.end()) {
				visit.clear();
				if (fun(iter->first)) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}