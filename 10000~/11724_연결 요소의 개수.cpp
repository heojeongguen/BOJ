#include <iostream>
#include <vector>
using namespace std;

int N, M, D1, D2, cnt = 0;
vector<int> vec[1001];
int visit[1001];

void DFS(int now) {
	visit[now] = true;

	for (int i = 0; i < vec[now].size(); i++) {
		if (visit[vec[now].at(i)] == false) DFS(vec[now].at(i));
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> D1 >> D2;
		vec[D1].push_back(D2);
		vec[D2].push_back(D1);
	}
	for(int i = 1; i <= N; i++) {
		if (visit[i] == false) {
			DFS(i);
			cnt++;
		}
	}
	cout << cnt << endl;
}