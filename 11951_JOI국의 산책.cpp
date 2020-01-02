#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------
#define MAXN 100001
class Info {
public:
	ll d; // 1 or 2
	ll s; // 시작 or 끝
	ll e;
	ll t; // 끝나느 시간
	Info(){}
	Info(int d, ll s, ll e, ll  t) {
		this->d = d;
		this->s = s;
		this->e = e;
		this->t = t;
	}
};
Info arr[MAXN]; // first : 최종위치, second : 끝나는시간

stack<pair<ll,ll>> s;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll N, T, Q;
	cin >> N >> T >> Q;
	ll last = 1e18 + 1;
	for (int i = 1; i <= N; i++) {
		ll x, d; cin >> x >> d;
		// 1은 ->, 2 <-
		if (d == 1) {
			s.push({ x,i });
		}
		else if(d == 2) {
			if (s.empty()) {
				if(last == 1e18 + 1)
					arr[i] = Info(2,x, 0,-1);
				else {
					arr[i] = Info(2, x,last, x - last);
				}
			}
			else {
				last = (x + s.top().first) / 2;
				//cout << " x : " << x << " top.fisrt : " << s.top().first << endl;
				// cout << "last : " << last << endl;
				arr[i] = Info(2,x, last, x - last);
				while (!s.empty()) {
					arr[s.top().second] = Info(1, s.top().first , last, last - s.top().first);
					s.pop();
				}
			}
		}
	}
	while (!s.empty()) {
		arr[s.top().second] = Info(1,s.top().first, 0,-1);
		s.pop();
	}
	for (int i = 0; i < Q; i++) {
		int data; cin >> data;
		ll t = arr[data].t;
		ll s = arr[data].s;
		ll e = arr[data].e;
		ll d = arr[data].d;
		if (t == -1) {
			if(d == 1) cout << s + T << endl;
			else cout << s - T << endl;
		}
		else {
			if (t < T) cout << e << endl;
			else {
				if (d == 1) cout << s + T << endl;
				else cout << s - T << endl;
			}
		}
	}
}