#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

int arr[501][501];
int dp[501][501];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0, 0, 1,-1 };
int visited[501][501];
int mmax = 0;
void dfs(int nowR, int nowC) {
	int value = 0;
	for (int i = 0; i < 4; i++) {
		int nextR = nowR + dx[i];
		int nextC = nowC + dy[i];
		if (nextR < n && nextR >= 0 && nextC < n && nextC >= 0) {
			if (arr[nowR][nowC] < arr[nextR][nextC]) {
				if (visited[nextR][nextC] == 0) dfs(nextR, nextC);

				if (value < visited[nextR][nextC])
					value = visited[nextR][nextC];
			}

		}
	}
	visited[nowR][nowC] = value + 1;
	mmax = max(visited[nowR][nowC], mmax);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				dfs(i, j);
			}
		}
	}
	cout << mmax << endl;
}