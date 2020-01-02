#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------

#define MAX_N 1001
vector<int> map[MAX_N];

int A[MAX_N];
int B[MAX_N];
bool visit[MAX_N];

bool dfs(int x) {
	visit[x] = true;
	for (int i = 0; i < map[x].size(); i++) {
		int y = map[x][i];
		if (B[y] == -1 || (visit[B[y]] == false && dfs(B[y]))) {
			A[x] = y;
			B[y] = x;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		for (int i = 0; i <= M; i++) {
			map[i].clear();
		}
		for (int i = 1; i <= M; i++) {
			int a, b; cin >> a >> b;
			for (int j = a; j <= b; j++) {
				map[i].push_back(j);
			}
		}

		memset(A, -1, sizeof(A));
		memset(B, -1, sizeof(B));
		int ans = 0;
		for (int i = 1; i <= M; i++) {
			if (A[i] == -1) {
				memset(visit, false, sizeof(visit));
				if (dfs(i)) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	
}