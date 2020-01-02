#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int> > vec[100001];
vector<int> vvec[100001];
bool visit[100001];
int parent[100001];
bool suc;
unsigned long long tmp;
void DFS(int now, int prev, unsigned long long cur,int find) {

	visit[now] = true;
	
	if (find == now) {
		suc = true;
		tmp = cur;
		return;
	}

	for (int i = 0; i < vec[now].size(); i++) {
		if (visit[vec[now][i].first] == false && prev != vec[now][i].first) {
			DFS(vec[now][i].first, now, cur + (unsigned long long)vec[now][i].second, find);
		}
	}
}

int Find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		int par = Find(parent[x]);
		parent[x] = par;
		return par;
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) {
		parent[y] = x;
	}
	vvec[x].push_back(y);
}

void setFalse(int x) {
	visit[x] = false;
	for (int i = 0; i < vvec[x].size(); i++) {
		setFalse(vvec[x][i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, Q, a, b, w;
	char tag;

	while (true) {
		cin >> N >> Q;
		if (N == 0 && Q == 0) break;

		for (int i = 0; i <= N; i++) {
			vec[i].clear();
		}
		
		for (int i = 1; i <= N; i++) {
			parent[i] = i;
			vvec[i].clear();
		}

;		for (int i = 0; i < Q; i++) {
			cin >> tag;
			if (tag == '!') {
				cin >> a >> b >> w;
				vec[a].push_back(make_pair(b, w));
				vec[b].push_back(make_pair(a, w * -1));
				
				Union(Find(a), Find(b));


			}
			else {
				cin >> a >> b;
				int root_a = Find(a);
				int root_b = Find(b);
				if (root_a != root_b) {
					cout << "UNKNOWN\n";
				}
				else {
					setFalse(root_a);
					suc = false;
					DFS(a, -1, 0, b);
					cout << tmp << "\n";
				}
			}
		}
	}
}