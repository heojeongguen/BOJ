#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec[501];
bool visit[501];

bool cycle = false;
int cnt = 0;
void dfs(int now, int prev) {

	visit[now] = true;

	for (int i = 0; i < vec[now].size(); i++) {
		if (visit[vec[now][i]] == false) {
			dfs(vec[now][i], now);
		}
		else {
			if (vec[now][i] != prev) {
				cycle = true;
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, a, b;
	int tc = 0;
	while (true) {
		tc++;
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		for (int i = 0; i <= n; i++) {
			vec[i].clear();
		}

		fill(visit, visit + 501, false);

		cnt = 0;

		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}


		for (int i = 1; i <= n; i++) {
			if (visit[i] == false){
				cycle = false;
				dfs(i, -1);
				if (!cycle) {
					cnt++;
				}
			}
		}

		cout << "Case " << tc << ": ";
		if (cnt == 0) {
			cout << "No trees." << endl;
		}
		else if (cnt == 1) {
			cout << "There is one tree." << endl;
		}
		else {
			cout << "A forest of " << cnt << " trees." << endl;
		}
	}
	return 0;
}