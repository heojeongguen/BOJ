#include <iostream>

using namespace std;

int arr[50][50];
int T;
int C, R, Q;
int y, x;
int r, c;
bool visit[50][50];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

void BFS(int nowR, int nowC) {
	visit[nowR][nowC] = true;
	for (int i = 0; i < 4; i++) {
		int nextR = nowR + dx[i];
		int nextC = nowC + dy[i];
		if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
		if (arr[nextR][nextC] == 1 && visit[nextR][nextC] == false) {
			BFS(nextR, nextC);
		}
	}
}

int main() {
	int cnt;
	cin >> T;
	while (T--) {
		cnt = 0;
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				visit[i][j] = false;
				arr[i][j] = 0;
			}
		}
		cin >> C >> R >> Q;
		for (int i = 0; i < Q; i++) {
			cin >> x >> y;
			arr[y][x] = 1;
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (arr[i][j] == 1 && visit[i][j] == false) {
					BFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
}