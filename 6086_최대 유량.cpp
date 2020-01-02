// ���� ǮĿ�� �˰���
// �ð����⵵ : O((E+V)*F):�־��� ��� �ִ�������ŭ * �� ���ܺ��⵵�� �ɸ���. -> ��ȿ������

// �ֵ��� ī�� �˰��� :: min( O(VE^2) or O(EF) )
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------
#define MAX_N 52
int c[MAX_N][MAX_N]; // �帣�� ��
int f[MAX_N][MAX_N]; // �帣�� �ִ� ��
int visit[MAX_N]; // �ѹ� que�� ��������(���������� ������ ������� �� ����) visit �� -1�� �ʱ�ȭ �ȴ�.
vector<int> vec[MAX_N];

// �ֵ��� ī�� �˰���
int maxFlow(int start, int end) {
	int ret = 0;
	while (1) {
		memset(visit, -1, sizeof(visit)); // ��� ���� �湮 �ʱ�ȭ
		queue<int> q;
		q.push(start); // start ������ end ������ ��� ������.
		while (!q.empty()) { 
			int x = q.front(); q.pop();
			for (int i = 0; i < vec[x].size(); i++) {
				int y = vec[x][i];
				if (c[x][y] - f[x][y] > 0 && visit[y] == -1) {
					// �带 �� �ִ� && �̹� BFS���� �帥���� ����.
					q.push(y);
					visit[y] = x; // x->y�� �귶�ٴ� ���� �˷��ش�.
					if (y == end) break; // end ���� ã�ԵǸ� flow ����
				}
			}
		}
		// ��� ��θ� ã�� ���
		if (visit[end] == -1) break; // BFS���� end ���� �湮���� �ʾҴ� -> ���̻� �帣�� ��찡 ���� -> Ż��
		int flow = INT_MAX; // flow : �ѹ��� �ִ�� ������� �� �ִ� ����
		for (int i = end; i != start; i = visit[i]) {
			flow = min(flow, c[visit[i]][i] - f[visit[i]][i]);
		}

		for (int i = end; i != start; i = visit[i]) {
			// ���� ������ �ִٰ� ���������ν� ��� ����� ���� Ž�� �� �� �ְ� �ȴ�.
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