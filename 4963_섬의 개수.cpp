#include <iostream>

using namespace std;

int arr[51][51];

int dx[8] = { 1,-1,0,0, 1, -1, 1, -1 };
int dy[8] = { 0,0,1,-1, 1, -1, -1, 1};

bool visit[51][51];
int C, R;
int cnt;
void DFS(int nowR, int nowC) {
	visit[nowR][nowC] = true;
	for (int i = 0; i < 8; i++) {
		int nextR = nowR + dx[i];
		int nextC = nowC + dy[i];

		if (nextR >= 0 && nextR < R && nextC >= 0 && nextC < C && visit[nextR][nextC] == false && arr[nextR][nextC] == 1) {
			DFS(nextR, nextC);
		}
	}
}

int main() {

	while (true) {
		cnt = 0;
		cin >> C >> R;
		if (R == 0 || C == 0) break;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> arr[i][j];
				visit[i][j] = false;
			}
		}


		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (arr[i][j] == 1 && visit[i][j] == false) {
					DFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
}