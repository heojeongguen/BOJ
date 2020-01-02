#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------
#define MAX 200002
class Info {
public:
	int x;
	int cost;
	Info(int x, int cost) {
		this->x = x;
		this->cost = cost;
	}
	bool operator < (const Info & b) const {
		return this->cost < b.cost;
	}
	bool operator > (const Info & b) const {
		return this->cost > b.cost;
	}
};

bool visit[MAX];
vector<pii> vec[MAX];
priority_queue<Info, vector<Info>, greater<> > pq;
ll mst() {
	ll ans = 0;
	pq.push(Info(0, 0));
	while (!pq.empty()) {
		Info t = pq.top(); pq.pop();
		int x = t.x;
		int xcost = t.cost;
		if (visit[x]) continue;
		visit[x] = true;
		ans += xcost;
		for (int i = 0; i < vec[x].size(); i++) {
			int y = vec[x][i].first;
			int ycost = vec[x][i].second;
			if (visit[y] == false) {
				pq.push(Info(y, ycost));
			}
		}
	}
	return ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m, n;
	while (cin >> m >> n) {
		ll total = 0;
		if (m == 0 && n == 0) break;
		for (int i = 0; i < MAX; i++) {
			vec[i].clear();
		}
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++) {
			int a, b, w;
			cin >> a >> b >> w;
			total += w;
			vec[a].push_back({ b,w });
			vec[b].push_back({ a,w });
		}
		cout << total - mst() << endl;
	}
}