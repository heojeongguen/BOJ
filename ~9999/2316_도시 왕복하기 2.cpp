#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------

#define MAXN 401
int c[MAXN][MAXN];
int f[MAXN][MAXN];
int visit[MAXN];
bool back[MAXN];
vector<int> vec[MAXN];

int maxFlow(int start, int end) {
	int ret = 0;
	while (1) {
		memset(visit, -1, sizeof(visit));
		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (int i = 0; i < vec[x].size(); i++) {
				int y = vec[x][i];
				if (c[x][y] - f[x][y] > 0 && visit[y] == -1) {
					q.push(y);
					visit[y] = x;
					if (y == end) break;
				}
			}
		}
		if (visit[end] == -1) break;
		int flow = INT_MAX;
		for (int i = end; i != start; i = visit[i]) {
			flow = min(flow, c[visit[i]][i] - f[visit[i]][i]);
		}
		for (int i = end; i != start; i = visit[i]) {
			f[visit[i]][i] += flow;
			f[i][visit[i]] -= flow;
		}
		ret += flow;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, P; cin >> N >> P;
	for (int i = 0; i < P; i++) {
		int a, b; cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
		c[a][b] += 1;
		c[b][a] += 1;
	}
}