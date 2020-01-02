#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <cstdio>
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
#define MAXN 100001
vector<int> vec[MAXN];
bool finished[MAXN];
stack<int> s;
int d[MAXN];
int id;
vector< vector<int> > SCC;
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
	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top(); s.pop();
			scc.push_back(t);
			finished[t] = true; // ó���Ϸ� flag
			d[t] = d[x];
			if (t == x) break;
		}
		SCC.push_back(scc);
	}

	return parent;
}


void fun(int x,int s) {
	d[x] = s;
	for (int i = 0; i < vec[x].size(); i++) {
		int y = vec[x][i];
		if (d[y] == 0) fun(y,s);
	}
}

int indeg[MAXN];
vector<int> check[MAXN];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int N, M;   scanf("%d%d", &N ,&M);
		int ans = 0;
		while (!s.empty()) s.pop();
		for (int i = 0; i <= N; i++) vec[i].clear();
		for (int i = 0; i <= N; i++) check[i].clear();
		memset(finished, false, sizeof(finished));
		memset(d, 0, sizeof(d));
		memset(indeg, 0, sizeof(indeg));
		SCC.clear();
		for (int i = 0; i < M; i++) {
			int x, y;  scanf("%d%d", &x, &y);
			vec[x].push_back(y);
			check[y].push_back(x);
			indeg[y]++;
		}
		for (int i = 1; i <= N; i++) {
			if (indeg[i] == 0) {
				fun(i,i);
				ans++;
			}
		}
		//cout << "ans1 : " << ans << endl;

		for (int i = 1; i <= N; i++) {
			if (d[i] == 0) {
				dfs(i);
			}
		}
		//cout << "SCC.size() : " << SCC.size() << endl;
		for (int i = 0; i < SCC.size(); i++) {
			bool find = false;
		//cout << "------------------------------\n";
			for (int j = 0; j < SCC[i].size(); j++) {
				int x = SCC[i][j];
				//cout << " x : " << x << endl;
				for (int z = 0; z <	 check[x].size(); z++) {
					int y = check[x][z];
					//cout << y << "->" << x << endl;
					//cout << "d[" << x << "] : " << d[x] << " d[" << y << "] : " << d[y] << endl;
					if (d[y] != d[x]) find = true;
				}
			}
			if (!find) ans++;	
		}
		printf("%d\n",ans);
	}
}