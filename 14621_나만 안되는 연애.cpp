/* 
	다익스트라 알고리즘
	or
	MST
	ors
	최소 신장 트리
*/

#include <iostream>
#include <vector>
using namespace std;


vector<pair<int,int>> vec[1001];
bool visit[1001];
char M_W[1001];
int root = -1;
int dis = -1;

int fuc(int now) {
	int ret = 0;
	for (int i = 0; i < vec[now].size(); i++) {
		if (visit[vec[now][i].first] == false) {
			visit[vec[now][i].first] = true;
			ret += vec[now][i].second + fuc(vec[now][i].first);
			visit[vec[now][i].first] = false;
		}
	}
	return ret;
}

int main() {
	// N : 학교수
	// M : 도로수
	int N, M;
	cin >> N >> M;
	char input;
	int a, b, c;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == 'M') M_W[i] = 'M';
		else M_W[i] = 'W';
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (M_W[a] != M_W[b]) {
			vec[a].push_back({ b,c });
			vec[b].push_back({ a,c });
		}
	}
}