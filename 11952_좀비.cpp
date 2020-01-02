#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------
#define MAXN 100001
vector<int> vec[MAXN];
bool zombie[MAXN];
int N, M, K, S;
int p, q;
vector<int> z;
ll visit[MAXN];
void dfs(int x, ll s) {
	if (s > S) {
		return;
	}
	if (visit[x] <= s) {
		return;
	}
	visit[x] = s;
	for (int i = 0; i < vec[x].size(); i++) {
		int y = vec[x][i];
		dfs(y, s + 1);
	}
}

class PQItem {
public:
	int x; ll cost;
	PQItem(int x, ll cost) {
		this->x = x;
		this->cost = cost;
	}
	bool operator < (const PQItem & b) const {
		return this->cost < b.cost;
	}
	bool operator > (const PQItem & b) const {
		return this->cost > b.cost;
	}
};

ll dist[MAXN];
priority_queue<PQItem, vector<PQItem>, greater<> > pq;
ll fuc() {
	pq.push(PQItem(1, 0));
	dist[1] = 0;
	while (!pq.empty()) {
		int x = pq.top().x;
		ll cost = pq.top().cost;
		pq.pop();

		if (dist[x] < cost) continue;
		for (int i = 0; i < vec[x].size(); i++) {
			int y = vec[x][i];
			if (zombie[y]) continue;
			ll ycost;

			if (visit[y] == LLONG_MAX) ycost = p;
			else ycost = q;

			if (dist[y] > cost + ycost) {
				dist[y] = cost + ycost;
				pq.push(PQItem(y, cost + ycost));
			}
		}
	}
	return dist[N];
}

int main() {
	// 해당 도시가 p인지 q인지만 알면 쉬움

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K >> S >> p >> q;
	for (int i = 0; i <= N; i++) {
		visit[i] = LLONG_MAX;
		dist[i] = LLONG_MAX;
	}
	for (int i = 0; i < K; i++) {
		int p; cin >> p;
		zombie[p] = true;
		z.push_back(p);
	}
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 0; i < z.size(); i++) {
		dfs(z[i], 0);
	}
	ll ret = fuc();
	if (visit[N] == LLONG_MAX) ret -= p;
	else ret -= q;
	cout << ret << endl;
}