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
#define MAX_N 501
vector<int> vec[MAX_N];
int A[MAX_N];
int B[MAX_N];
bool visit[MAX_N];

bool dfs(int x) {
	if (visit[x]) return false;
	visit[x] = true;
	for (int i = 0; i < vec[x].size(); i++) {
		int y = vec[x][i];
		if (B[y] == -1 || dfs(B[y])) {
			A[x] = y;
			B[y] = x;
			return true;
		}
	}
	return false;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int x, y; cin >> x >> y;
		vec[x].push_back(y);
	}
	int ans = 0;
	memset(B, -1, sizeof(B));
	memset(A, -1, sizeof(A));
	for (int i = 1; i <= n; i++) {
		if (A[i] == -1) {
			memset(visit, false, sizeof(visit));
			if (dfs(i)) ans++;
		}
	}
	cout << ans << endl;
}