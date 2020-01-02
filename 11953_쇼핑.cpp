#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------
int arr[1002][1002];
int R, C;
pii dxdy[4] = { {1,0},{0,1},{-1,0}, {0,-1} };
// 내가 위에서 왔는지 왼쪾에서 왔는지 살껀지 안살껀지
int dp[1001][1001][2];
bool visit[1001][1001];
int dfs(int x, int y, int px, int py) {
	int z;
	if (x == px) z = 0;
	else z = 1;

	if (dp[x][y][z] != -1) return dp[x][y][z];
	if (x == R && y == C){
		return arr[x][y]; 
	}	
	int ret = 1e9;
	int now = 0;
	if (!visit[x][y]) now = arr[x][y];
	visit[x][y] = true;
	// 잡아 먹은 상태에서 2가지 방향을 보내야지;
	// 방향을 정해놓고 먹고 근데 결관느 같은거아냐?
	vector<pii> eat;
	for (int i = 0; i < 4; i++) {
		int ex = x + dxdy[i].first;
		int ey = y + dxdy[i].second;
		if (arr[ex][ey] > 0 && !visit[ex][ey]) {
			eat.push_back({ ex,ey });
		}
	}
	if (eat.size() == 1 || eat.size() == 0) {
		int tmp = now;
		for (int i = 0; i < 2; i++) {
			int nx = x + dxdy[i].first;
			int ny = y + dxdy[i].second;
			if (nx < 0 || nx > R || ny < 0 || ny > C) continue;
			tmp += dfs(nx, ny, x, y);
			ret = min(ret, tmp);
		}
	}else{
		for (int j = 0; j < eat.size(); j++) {
			int tmp = now;
			vector<pii> eated;
			for (int k = 0; k < eat.size(); k++) {
				if (j == k) continue;
				int ex = eat[k].first;
				int ey = eat[k].second;
				visit[ex][ey] = true;
				eated.push_back({ ex ,ey });
				tmp += arr[ex][ey];
			}
			int tmp2 = tmp;
			for (int i = 0; i < 2; i++) {
				int nx = x + dxdy[i].first;
				int ny = y + dxdy[i].second;
				if (nx < 0 || nx > R || ny < 0 || ny > C) continue;
				tmp2 += dfs(nx, ny, x, y);
				ret = min(ret, tmp2);
			}
			for (const auto &en : eated) {
				visit[en.first][en.second] = false;
			}
		}
	}
	visit[x][y] = false;
	dp[x][y][z] = ret;
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> R >> C;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			char c; cin >> c;
			if (c == '.') arr[i][j] = 0;
			else {
				int d = c - '0';
				arr[i][j] = d;
			}
		}
	}
	cout << dfs(1, 1, 0, 0) << endl;
}