#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<int,int> tree[10001];
int par[10001];
vector<int> width[10001];
int childCount(int now, int cur, int lev) {
	int ret = cur;
	if (tree[now].first == -1 && tree[now].second == -1) {
		width[lev].push_back(ret);
		return ret;
	}

	if (tree[now].first != -1) {
		ret = 1 + childCount(tree[now].first, cur, lev + 1);
	}

	width[lev].push_back(ret);

	if (tree[now].second != -1) {
		ret = childCount(tree[now].second, ret + 1, lev + 1);
	}
	return ret;
}




int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, p, l, r,root;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p >> l >> r;
		tree[p].first = l;
		tree[p].second = r;
		par[l] = p;
		par[r] = p;
	}

	for (int i = 1; i <= N; i++) {
		if (par[i] == 0) {
			root = i;
			break;
		}
	}
	int lev = -1;
	int ans = -1;

	childCount(root, 0, 1);

	for (int i = 1; i <= N; i++) {
		if (width[i].empty()) break;
		sort(width[i].begin(), width[i].end());
		int dis = abs(width[i].front() - width[i].back()) + 1;
		if (ans < dis) {
			ans = dis;
			lev = i;
		}
	}
	cout << lev << " " << ans << endl;
}