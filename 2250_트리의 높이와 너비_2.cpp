#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<int, int> map[10001];
int root;
int parent[10001];
int leftCount[10001];
vector<int> width[100001];

int cnt_ch(int now, int len, int lev) {
	int ret = len;

	if (map[now].first == -1 && map[now].second == -1) {
		width[lev].push_back(ret);
		leftCount[now] = len;
		return ret;
	}

	if (map[now].first != -1) {
		ret = 1 + cnt_ch(map[now].first, ret, lev + 1);
	}
	// ret은 현재 자기기준 왼쪾에있는 녀석들;
	leftCount[now] = ret;
	width[lev].push_back(ret);

	// 자기기준 왼쪽에있는 녀석들에 자기(1)를 더해서 오른쪽자식에게 넘겨줌.
	if (map[now].second != -1) {
		ret = cnt_ch(map[now].second, ret + 1, lev + 1);
	}

	return ret;
}

int main() {
	int N,par,left ,right;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> par >> left >> right;
		map[par].first = left;
		map[par].second = right;
		parent[left] = par;
		parent[right] = par;
	}
	for (int i = 1; i <= N; i++) {
		if (parent[i] == 0) {
			root = i;
			break;
		}
	}

	cnt_ch(root,0,1);
	int ans = -1;
	int lev = -1;
	for (int i = 1; i <= 10000; i++) {
		if (width[i].empty()) break;
		sort(width[i].begin(), width[i].end());
		if (ans < abs(width[i].front() - width[i].back()) + 1) {
			ans = abs(width[i].front() - width[i].back()) + 1;
			lev = i;
		}
	}
	cout << lev << " " << ans << endl;
}