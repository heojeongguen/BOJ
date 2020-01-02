#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------

#define MAX_N 1001
vector<int> vec[MAX_N];
int A[MAX_N];
int B[MAX_N];
bool visit[MAX_N];

bool fun(int x) {
	visit[x] = true;
	for (int i = 0; i < vec[x].size(); i++) {
		int y = vec[x][i];
		if (B[y] == -1 || (!visit[B[y]] && fun(B[y]))) {
			A[x] = y;
			B[y] = x;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int s; cin >> s;
		for (int j = 0; j < s; j++) {
			int data; cin >> data;
			vec[i].push_back(data);
		}
	}
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (A[i] == -1) {
			memset(visit, false, sizeof(visit));
			if (fun(i)) ans++;
		}
	}
	cout << ans << endl;
}