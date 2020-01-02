// 포드 풀커슨 알고리즘
// 시간복잡도 : O((E+V)*F):최악의 경우 최대유량만큼 * 의 시잔복잡도가 걸린다. -> 비효율적임

// 애드몬드 카프 알고리즘 :: min( O(VE^2) or O(EF) )
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------
#define MAX_N 52
int c[MAX_N][MAX_N]; // 흐르는 양
int f[MAX_N][MAX_N]; // 흐르고 있는 양
int visit[MAX_N]; // 한번 que가 돌때마다(시작점에서 유량을 흘려보낼 때 마다) visit 이 -1로 초기화 된다.
vector<int> vec[MAX_N];

// 애드몬드 카프 알고리즘
int maxFlow(int start, int end) {
	int ret = 0;
	while (1) {
		memset(visit, -1, sizeof(visit)); // 모든 정점 방문 초기화
		queue<int> q;
		q.push(start); // start 점에서 end 점까지 흘려 보낸다.
		while (!q.empty()) { 
			int x = q.front(); q.pop();
			for (int i = 0; i < vec[x].size(); i++) {
				int y = vec[x][i];
				if (c[x][y] - f[x][y] > 0 && visit[y] == -1) {
					// 흐를 수 있다 && 이번 BFS에서 흐른적이 없다.
					q.push(y);
					visit[y] = x; // x->y로 흘렀다는 것을 알려준다.
					if (y == end) break; // end 점을 찾게되면 flow 중지
				}
			}
		}
		// 모든 경로를 찾은 경우
		if (visit[end] == -1) break; // BFS에서 end 점을 방문하지 않았다 -> 더이상 흐르는 경우가 없다 -> 탈출
		int flow = INT_MAX; // flow : 한번에 최대로 흘려보낼 수 있는 유량
		for (int i = end; i != start; i = visit[i]) {
			flow = min(flow, c[visit[i]][i] - f[visit[i]][i]);
		}

		for (int i = end; i != start; i = visit[i]) {
			// 음의 간선이 있다고 생각함으로써 모든 경우의 수를 탐색 할 수 있게 된다.
			// x->y += flow, y->x -= flow;
			f[visit[i]][i] += flow;
			f[i][visit[i]] -= flow;
		}
		ret += flow;
	}
	return ret;
}

int getID(char c) {
	int ret;
	if (c >= 97) {
		ret = c - 97;
		ret += 26;
	}
	else {
		ret = c - 65;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		char a, b; int w; cin >> a >> b >> w;
		int A = getID(a);
		int B = getID(b);
		vec[A].push_back(B);
		vec[B].push_back(A);
		c[A][B] += w;
		c[B][A] += w;
	}
	cout << maxFlow(0, 25) << endl;
}