#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------
int arr[101][101];
int N;
pii dxdy[4] = { {1,0},{-1,0},{0,1},{0,-1} };
class QueItem {
public:
	int x, y, cost;
	QueItem(int x, int y, int cost) {
		this->x = x; this->y = y; this->cost = cost;
	}
	bool operator < (const QueItem & b) const {
		return this->cost < b.cost;
	}
	bool operator > (const QueItem & b) const {
		return this->cost > b.cost;
	}
};

int dist[101][101];

int BFS() {
	priority_queue<QueItem,vector<QueItem>,greater<QueItem> > pq;
	pq.push(QueItem(0, 0, 0));
	dist[0][0] = 0;
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int cost = pq.top().cost;
		pq.pop();
		if (dist[x][y] < cost) continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + dxdy[i].first;
			int ny = y + dxdy[i].second;
			int ncost = arr[nx][ny];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (dist[nx][ny] > cost + ncost) {
				pq.push(QueItem(nx, ny, cost + ncost));
				dist[nx][ny] = cost + ncost;
			}
		}
	}
	return dist[N - 1][N - 1];
}



int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				char c; cin >> c;
				int data = c - '0';
				arr[i][j] = data;
				dist[i][j] = 1e9;
			}
		}
		cout <<"#" << t <<" "<<  BFS() << endl;
	}
}