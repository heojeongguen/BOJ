#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int> > vec[100001];
int par[100001];
bool visit[100001];
pair<int, int> tmp = { -1,-1 };
void find_node(int now, int len) {
	visit[now] = true;

	bool nothing = true;

	for (int i = 0; i < vec[now].size(); i++){
		if (visit[ vec[now][i].first ] == false) {
			nothing = false;
			find_node(vec[now][i].first, len + vec[now][i].second);
		}
	}

	if (nothing) {
		if( tmp.second < len ){
			tmp.first = now;
			tmp.second = len;
		}
	}
}

void find_len(int now, int len) {
	visit[now] = true;
	bool nothing = true;

	for (int i = 0; i < vec[now].size(); i++) {
		if (visit[vec[now][i].first] == false) {
			nothing = false;
			find_len(vec[now][i].first, len + vec[now][i].second);
		}
	}

	if (nothing) {
		if (tmp.second < len) {
			tmp.first = now;
			tmp.second = len;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	int v, v2, wei;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v;
		while (true) {
			cin >> v2;
			if (v2 == -1) break;
			cin >> wei;
			vec[v].push_back(make_pair(v2, wei));
			vec[v2].push_back(make_pair(v, wei));
			par[v]++;
			par[v2]++;
		}
	}
	// 트리의 지름은 우선 루트에서 가장 멀리있는 거 찾고
	// 멀리있는거로부터 제일 멀리있는거 찾으면됨.
	int root = -1;
	for (int i = 1; i <= N; i++) {
		if (par[i] == 1) {
			root = i;
			break;
		}
	}
	find_node(1, 0);
	fill(visit, visit+ 100001, false);
	root = tmp.first;
	tmp = { -1,-1 };
	find_len(root, 0);
	cout << tmp.second << endl;
}