#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------
#define MAXN 500001
int id, d[MAXN], money[MAXN];
vector<vector<int> > SCC;
vector<int> vec[MAXN];
bool finished[MAXN];
stack<int> st;
int SCCId[MAXN];
vector<int> vvec[MAXN];
bool res[MAXN];
int dfs(int x) {
	d[x] = ++id;
	st.push(x);

	int parent = d[x];
	for (int i = 0; i < vec[x].size(); i++) {
		int y = vec[x][i];
		if (d[y] == 0) parent = min(parent, dfs(y));
		else if (!finished[y]) parent = min(parent, d[y]);
	}

	if (parent == d[x]) {
		vector<int> scc;
		int size = SCC.size();
		while (1) {
			int top = st.top(); st.pop();
			scc.push_back(top);
			finished[top] = true;
			d[top] = parent;
			SCCId[top] = size;
			if (top == x) break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

int ans = 0;
ll dp[MAXN];

ll ddfs(int x) {
	ll ret = dp[x], tmp = 0, sum = 0;
	bool hasRes = false;
	if (dp[x] != -1) return dp[x];

	for (int i = 0; i < vvec[x].size(); i++) {
		tmp = max(tmp,ddfs(vvec[x][i]));
	}

	for (int i = 0; i < SCC[x].size(); i++) {
		sum += money[SCC[x][i]];
		if (res[SCC[x][i]]) hasRes = true;
	}

	if (tmp == 0) {
		if (!hasRes) {
			dp[x] = 0;
		}
		else {
			dp[x] = sum;
		}
	}
	else {
		dp[x] = tmp + sum;
	}
	return dp[x];
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, M, S, P; cin >> N >> M;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < M; i++) {
		int x, y; cin >> x >> y;
		vec[x].push_back(y);
	}
	for (int i = 1; i <= N; i++) {
		cin >> money[i];
	}
	cin >> S >> P;
	for (int i = 0; i < P; i++) {
		int p; cin >> p;
		res[p] = true;
	}

	for (int i = 1; i <= N; i++) {
		if (d[i] == 0) dfs(i);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			if (SCCId[i] != SCCId[vec[i][j]]) 
				vvec[SCCId[i]].push_back(SCCId[vec[i][j]]);
		}
	}
	S = SCCId[S];
	cout << ddfs(S) << endl;
}