#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------
#define MAX 10001
int id, d[MAX];
bool finished[MAX];
vector<int> vec[10001];
vector<vector<int> > SCC;
stack<int> s;

// DFS 는 총정점의 갯수만큼 실행된다.
int dfs(int x) {
	d[x] = ++id; // 노드번호와 상관없이 방문 순서를 의미한다
	s.push(x); // stack push

	int parent = d[x]; // 초기 부모는 자기 자신
	for (int i = 0; i < vec[x].size(); i++) {
		int y = vec[x][i]; // 연결된 이웃 노드
		
		// 한번도 방문하지 않는 이웃 노드
		// 이웃 노드의 dfs의 결과값(부모값)과 자신의 부모값중 작은놈을 부모로 설정 ( 문제에 따라 다름 )
		if (d[y] == 0) parent = min(parent, dfs(y));

		// 방문은 이미 했으나, stack에 남아있는 노드
		// 자신의 부모와 이웃노드의 부모중 작은놈을 부모값으로 설정
		else if (!finished[y]) parent = min(parent, d[y]); // stack에 들어있는 이웃 노드
	}

	// DFS FINISH!!!
	// 자신이 SCC의 대표일경우
	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top(); s.pop();
			scc.push_back(t); 
			finished[t] = true; // 처리완료 flag
			d[t] = d[x];
			if (t == x) break; 
		}
		// SCC group vector에 scc를 추가해준다
		SCC.push_back(scc);
	}

	return parent;
}

bool cmp(const vector<int> &vec1, const vector<int> &vec2) {
	return vec1[0] < vec2[0];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int V, E; cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b; cin >> a >> b;
		// 방향그래프에서만 SCC문제가 유효하다.( 무방향에서는 전체 그래프 자체가 하나의 SCC )
		vec[a].push_back(b);
	}
	for (int i = 1; i <= V; i++) {
		// 한번도 방문하지 않은경우에
		if (d[i] == 0) dfs(i);
	}
	cout << SCC.size() << endl;
	for (int i = 0; i < SCC.size(); i++) {
		sort(SCC[i].begin(), SCC[i].end());
	}
	sort(SCC.begin(), SCC.end(), cmp);

	for (int i = 0; i < SCC.size(); i++) {
		for (const auto &x : SCC[i]) {
			cout << x << " ";
		}
		cout << -1 << endl;
	}
}