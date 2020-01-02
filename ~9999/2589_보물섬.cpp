#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define endl '\n'
typedef long long ll;

int R, C;
char arr[51][51];
int visited[51][51];
int check[51][51];

pair<int, int> dxdy[4] = { {1,0},{-1,0 },{0,1 },{0,-1 } };
pair<int, pair<int, int> > startPoint;

class QueItem {
public:
	int d;
	int r;
	int c;
	QueItem() {
		d = 0;
		r = 0;
		c = 0;
	}
	QueItem(int r, int c, int d) {
		this->r = r;
		this->c = c;
		this->d = d;
	}
	bool operator >(QueItem const& b) const {
		return this->d > b.d;
	}
};

int ans= 0;
int dist[51][51];

void fun(int r, int c) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			dist[i][j] = 1e9;
		}
	}
	priority_queue<QueItem, vector<QueItem>, greater<QueItem> > pq;
	pq.push(QueItem(r, c, 0));
	dist[r][c] = 0;
	while (!pq.empty()) {
		QueItem t = pq.top(); pq.pop();
		int nowR = t.r;
		int nowC = t.c;
		int nowD = t.d;
		if (dist[nowR][nowC] < nowD) continue;
		ans = max(ans, nowD);
		for (int i = 0; i < 4; i++) {
			int nextR = nowR + dxdy[i].first;
			int nextC = nowC + dxdy[i].second;
			int nextD = nowD + 1;
			if (arr[nextR][nextC] == 'W') continue;
			if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
			if (dist[nextR][nextC] > nextD) {
				pq.push(QueItem(nextR, nextC, nextD));
				dist[nextR][nextC] = nextD;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char c; cin >> c;
			arr[i][j] = c;
			visited[i][j] = false;
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 'L') {
				fun(i, j);
			}
		}
	}
	cout << ans << endl;
}