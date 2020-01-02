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
int arr[101][101];
bool visit[101][101];
pii dxdy[3] = { {0,1}, {0,-1},{-1,0}, };
int dfs(int x, int y) {
	visit[x][y] = true;
	if (x == 0) {
		return y;
	}

	for (int i = 0; i < 3; i++) {
		int nx = x + dxdy[i].first;
		int ny = y + dxdy[i].second;
		if (ny < 0 || ny >= 100) continue;
		if (visit[nx][ny]) continue;
		if (arr[nx][ny] == 1) {
			return dfs(nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	while (cin >> t) {
		int ex, ey;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				int data; cin >> data;
				arr[i][j] = data;
				if (data == 2) {
					ex = i;
					ey = j;
				}
			}
		}
		cout << "#" << t << " " << dfs(ex, ey) << endl;
	}
}