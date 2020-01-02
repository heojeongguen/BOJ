#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
vector<ll> sands;
vector<pair<ll, ll> > ani;

ll getDist(ll x, ll x1, ll y1) {
	return abs(x - x1) + y1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int M, N, L; cin >> M >> N >> L;
	ll MAX = 1000000001;
	for (int i = 0; i < M; i++) {
		ll x; cin >> x;
		sands.push_back(x);
	}
	for (int i = 0; i < N; i++) {
		ll x, y; cin >> x >> y;
		ani.push_back({ x,y });
	}
	sands.push_back(-MAX);
	sands.push_back(MAX);
	sort(sands.begin(), sands.end());
	sort(ani.begin(), ani.end());
	int ans = 0;
	for (int i = 0; i < ani.size(); i++) {
		ll x = ani[i].first;
		ll y = ani[i].second;
		auto left = lower_bound(sands.begin(), sands.end(), x);
		auto right = left - 1;
		if (min(getDist(*right, x, y), getDist(*left, x, y)) <= L) ans++;
	}
	cout << ans;
}