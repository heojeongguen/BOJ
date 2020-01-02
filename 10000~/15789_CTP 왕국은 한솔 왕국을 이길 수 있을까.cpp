#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visit[100001];
vector<int> vec[100001];
vector<int> alias;
int dfs(int now) {
	visit[now] = true;
	int ret = 1;
	for (int i = 0; i < vec[now].size(); i++) {
		if (visit[vec[now][i]] == false) {
			ret += dfs(vec[now][i]);
		}
	}
	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	int C, H, K;
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	cin >> C >> H >> K;
	int C_cnt = dfs(C); dfs(H);

	for (int i = 1; i <= N; i++) {
		if (visit[i] == false) {
			alias.push_back(dfs(i));
		}
	}

	sort(alias.begin(), alias.end(),greater<int>());


	int ans = 0;
	int size = alias.size();
	for (int i = 0; i < K; i++) {
		if (i == size) break;
		else ans += alias[i];
	}
	cout << ans + C_cnt << endl;
}