#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, Q, r1, c1, r2, c2, cnt, area;

int arr[101][101];

bool visited[101][101];

int dx[4] = { 1, -1, 0 , 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<int> ans;
void BFS(int nowR, int nowC) {

	visited[nowR][nowC] = true;

	for (int i = 0; i < 4; i++) {
		int nextR = dx[i] + nowR;
		int nextC = dy[i] + nowC;
		if (nextR >= 0 && nextR < R && nextC >= 0 && nextC < C) {
			if (visited[nextR][nextC] == false && arr[nextR][nextC] == 0) {
				BFS(nextR, nextC);
			}
		}
	}
	area++;
}

int main() {

	cin >> R >> C >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> r1 >> c1 >> r2 >> c2;
		int tmp = c1;

		c1 = r1;
		r1 = R - tmp;
		tmp = c2;
		c2 = r2;
		r2 = R - tmp;

		int rr1 = min(r1, r2);
		int rr2 = max(r1, r2);
		int cc1 = min(c1, c2);
		int cc2 = max(c1, c2);
		for (int j = rr1; j <= rr2-1; j++) {
			for (int z = cc1; z <= cc2-1; z++) {
				arr[j][z] = 1;
			}
		}
	}


	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j] == false && arr[i][j] == 0) {
				cnt++;
				area = 0;
				BFS(i, j);
				ans.push_back(area);
			}
		}
	}

	cout << cnt << endl;
	sort(ans.begin(), ans.end());
	for (const auto &x : ans) {
		cout << x << endl;
	}
}