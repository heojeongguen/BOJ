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
int arr[17][17];
bool visit[17][17];
pair<int, int> dxdy[4] = { {1,0},{-1,0},{0,1},{0,-1} };
int BFS(int sx, int sy) {
	queue<pair<int, int> > que;
	que.push({ sx,sy });
	visit[sx][sy] = true;
	bool suc = false;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dxdy[i].first;
			int ny = y + dxdy[i].second;
			if (nx < 0 || nx >= 16 || ny < 0 || ny >= 16) continue;
			if (visit[nx][ny]) continue;
			if (arr[nx][ny] == 1) continue;
			que.push({ nx,ny });
			visit[nx][ny] = true;
			if (arr[nx][ny] == 3) suc = true;
		}
	}
	return suc;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for(int T = 0 ; T < 10; T++){
		int t; cin >> t;
		int sx, sy;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				char c; cin >> c;
				int data = c - '0';
				arr[i][j] = data;
				if (arr[i][j] == 2) {
					sx = i;
					sy = j;
				}
			}
		}
		bool ret = BFS(sx,sy);
		if (ret) cout << "#" << t << " " << 1 << endl;
		else cout << "#" << t << " " << 0 << endl;
	}
}