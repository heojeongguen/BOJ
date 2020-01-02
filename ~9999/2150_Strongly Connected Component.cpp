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

// DFS �� �������� ������ŭ ����ȴ�.
int dfs(int x) {
	d[x] = ++id; // ����ȣ�� ������� �湮 ������ �ǹ��Ѵ�
	s.push(x); // stack push

	int parent = d[x]; // �ʱ� �θ�� �ڱ� �ڽ�
	for (int i = 0; i < vec[x].size(); i++) {
		int y = vec[x][i]; // ����� �̿� ���
		
		// �ѹ��� �湮���� �ʴ� �̿� ���
		// �̿� ����� dfs�� �����(�θ�)�� �ڽ��� �θ��� �������� �θ�� ���� ( ������ ���� �ٸ� )
		if (d[y] == 0) parent = min(parent, dfs(y));

		// �湮�� �̹� ������, stack�� �����ִ� ���
		// �ڽ��� �θ�� �̿������ �θ��� �������� �θ����� ����
		else if (!finished[y]) parent = min(parent, d[y]); // stack�� ����ִ� �̿� ���
	}

	// DFS FINISH!!!
	// �ڽ��� SCC�� ��ǥ�ϰ��
	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top(); s.pop();
			scc.push_back(t); 
			finished[t] = true; // ó���Ϸ� flag
			d[t] = d[x];
			if (t == x) break; 
		}
		// SCC group vector�� scc�� �߰����ش�
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
		// ����׷��������� SCC������ ��ȿ�ϴ�.( �����⿡���� ��ü �׷��� ��ü�� �ϳ��� SCC )
		vec[a].push_back(b);
	}
	for (int i = 1; i <= V; i++) {
		// �ѹ��� �湮���� ������쿡
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