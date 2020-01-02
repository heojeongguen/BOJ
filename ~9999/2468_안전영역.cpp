#include <iostream>
#include <algorithm>
using namespace std;

int A[101][101];
int N;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visit[101][101];
void BFS(int nowR, int nowC, int h) {
	visit[nowR][nowC] = true;

	for (int i = 0; i < 4; i++) {
		int nextR = nowR + dx[i];
		int nextC = nowC + dy[i];
		if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N || visit[nextR][nextC] == true) continue;
		if (A[nextR][nextC] > h) {
			BFS(nextR, nextC, h);
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int mmax = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			mmax = max(A[i][j], mmax);
		}
	}
	int cnt;
	for (int h = 0; h <= mmax; h++) {
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = false;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (A[i][j] > h && visit[i][j] == false) {
					cnt++;
					BFS(i, j, h);
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}