#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> tree[10001];

int ch[10001];

vector<int> width[10001];

int cnt_ch(int now, int len,int lev) {
	int ret = len;
	if (tree[now].first == -1 && tree[now].second == -1) {
		ch[now] = len;
		width[lev].push_back(ret);
		return ret;
	}
	if (tree[now].first != -1) {
		ret = 1 + cnt_ch(tree[now].first, ret, lev+1);
	}

	ch[now] = ret;
	width[lev].push_back(ret);

	if (tree[now].second != -1) {
		ret = cnt_ch( tree[now].second, ret + 1, lev + 1);
	}

	return ret;
}

int par[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	int root, left, right;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		tree[i].first = -1;
		tree[i].second = -1;
	}
	for (int i = 0; i < N; i++) {
		cin >> root >> left >> right;
		tree[root].first = left;
		tree[root].second = right;
		par[left] = root;
		par[right] = root;
	}
	
	int root_node = -1;
	for (int i = 1; i <= N; i++) {
		if (par[i] == 0) {
			root_node = i;
			break;
		}
	}
	cnt_ch(root_node, 0, 1);

	pair<int, int> ans = { 0,0 };
	for (int i = 1; i < 10001; i++) {
		if (width[i].empty()) break;

		sort(width[i].begin(), width[i].end());
		if (ans.second < abs(width[i].front() - width[i].back())) {
			ans.first = i;
			ans.second = abs(width[i].front() - width[i].back());
		}
	}
	cout << max( 1, ans.first ) << " " << ans.second + 1 <<  endl;
}