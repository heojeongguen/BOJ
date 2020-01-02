#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int> > vec[10001];

pair<int, int> tmp = { -1,-1 };
pair<int, int> tmp2 = { -1,-1 };

bool visit[10001];

void find_node(int now, int len) {
	visit[now] = true;

	bool nothing = true;

	for (int i = 0; i < vec[now].size(); i++) {
		if (visit[vec[now][i].first] == false) {
			find_node(vec[now][i].first, len + vec[now][i].second);
			nothing = false;
		}
	}


	if (nothing) {
		if (tmp.second < len) {
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
			find_len(vec[now][i].first, len + vec[now][i].second);
			nothing = false;
		}
	}
	if (nothing) {
		if (tmp2.second < len) {
			tmp2.first = now;
			tmp2.second = len;
		}
	}
}

int main() {
	// 루트로 부터 가장 멀리있는 노드 찾고
	// 그 노드로부터 가장 멀리있는 것이 답이다!
	int N;

	cin >> N;
	int root, left, right;
	for (int i = 0; i < N - 1; i++) {
		cin >> root >> left >> right;
		vec[root].push_back(make_pair(left, right));
		vec[left].push_back(make_pair(root, right));
	}
	fill(visit, visit + 10001, false);
	find_node(1, 0);


	fill(visit, visit + 10001, false);
	find_len(tmp.first, 0);
	cout << tmp2.second << endl;
}