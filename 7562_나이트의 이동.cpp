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
pii dxdy[8] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };
bool visit[301][301];
int X, Y, L;

class Info {
public:
	int x, y, cnt;
	Info(int x, int y, int cnt) {
		this->x = x; this->y = y; this->cnt = cnt;
	}
};

int bfs(int sx, int sy) {
	queue<Info> que;
	memset(visit, false, sizeof(visit));
	visit[sx][sy] = true;
	que.push(Info( sx,sy,0 ));
	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int cnt = que.front().cnt;
		if (x == X && y == Y) {
			return cnt;
		}
		que.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dxdy[i].first;
			int ny = y + dxdy[i].second;
			if (nx < 0 || nx >= L || ny < 0 || ny >= L) continue;

			if (visit[nx][ny] == false) {
				que.push(Info(nx,ny,cnt+1));
				visit[nx][ny] = true;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		 cin >> L;
		 int x, y;
		 cin >> x >> y >> X >> Y;
		 cout << bfs(x, y) << endl;
	}
}