#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
vector<pair<int, int> > vec[1001];
int needed[1001];

int dfs(int now, int prev) {
	int ret = 0;
	for (int i = 0; i < vec[now].size(); i++) {
		if (vec[now][i].first == prev) continue;
		ret += min(dfs(vec[now][i].first, now), vec[now][i].second);
	}
	//cout << "prev : " << prev << " now : " << now << " ret :  " << ret << endl;
	if (ret == 0) return 10000001;
	else return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int V, E;
		int a, b, c;
		cin >> V >> E;
		for (int i = 0; i < E; i++) {
			cin >> a >> b >> c;
			vec[a].push_back({b,c});
			vec[b].push_back({a,c});
		}
		if (V == 1) cout << 0 << endl;
		else cout << dfs(1, -1) << endl;
		for (int i = 1; i <= V; i++) {
			vec[i].clear();
			needed[i] = 0;
		}
	}
	
}