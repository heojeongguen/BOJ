#include <iostream>
#include <algorithm>
using namespace std;
int R, C, K, D1, D2;
int arr[101][101];
int visit[101][101];
int cnt;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0, 0 ,1, -1 };
void BFS(int nowR, int nowC) {
	cnt++;
	visit[nowR][nowC] = true;

	for (int i = 0; i < 4; i++) {
		int nextR = dx[i] + nowR;
		int nextC = dy[i] + nowC;
		if (nextR > 0 && nextR <= R && nextC > 0 && nextC <= C && visit[nextR][nextC] == false && arr[nextR][nextC] == 1) {
			BFS(nextR, nextC);
		}
	}
}

int main() {
	cin >> R >> C >> K;
	int mmax = 0;
	for (int i = 0; i < K; i++) {
		cin >> D1 >> D2;
		arr[D1][D2] = 1;
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (visit[i][j] == false && arr[i][j] == 1) {
				cnt = 0;
				BFS(i, j);
				mmax = max(cnt, mmax);
			}
		}
	}
	cout << mmax << endl;
}
