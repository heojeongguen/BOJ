#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visit[502];
vector<int> vec[502];
queue<int> que;
int cnt = 0;

int main() {
	int N;
	int Q;
	int a, b;
	cin >> N >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	fill(visit, visit + 502, false);
	visit[1] = true;
	if (!vec[1].empty()) {
		for (int i = 0; i < vec[1].size(); i++) {
			que.push(vec[1][i]);
			cnt++;
			visit[vec[1][i]] = true;
		}
		while (!que.empty()) {
			for (int i = 0; i < vec[que.front()].size(); i++) {
				if (visit[vec[que.front()][i]] == false) {
					visit[vec[que.front()][i]] = true;
					cnt++;
				}
			}
			que.pop();
		}
	}
	cout << cnt << endl;
}