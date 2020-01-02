#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace  std;

int arr[102][102];
int dp[102][102];
bool flag[102][102];
int R, C;
void BFS(int row, int col) {
	queue<pair<int,int>> que;
	que.push(make_pair(row, col));
	int move = 1;
	while (!que.empty()) {
		queue<pair<int, int>> tmp;
		while (!que.empty()) {
			int r = que.front().first;
			int c = que.front().second;
			if (r + 1 < R && arr[r + 1][c] == 1 && flag[r + 1][c] == false) {
				flag[r + 1][c] = true;
				dp[r + 1][c] = move;
				tmp.push(make_pair(r + 1, c));
			}
			if (c + 1 < C && arr[r][c + 1] == 1 && flag[r][c + 1] == false) {
				flag[r][c + 1] = true;
				dp[r ][c+1] = move;
				tmp.push(make_pair(r , c+1));
			}
			if (r - 1 >= 0 && arr[r - 1][c] == 1 && flag[r - 1][c] == false) {
				flag[r - 1][c] = true;
				dp[r-1][c] = move;
				tmp.push(make_pair(r - 1, c));
			}
			if (c - 1 >= 0 && arr[r][c - 1] == 1 && flag[r][c - 1] == false) {
				flag[r][c - 1] = true;
				dp[r][c-1] = move;
				tmp.push(make_pair(r, c-1));
			}
			que.pop();
		}
		que = tmp;
		move++;
	}
}


int main() {

	cin >> R >> C;
	string str;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			dp[i][j] = INT_MAX - 1;
		}
	}

	for (int i = 0; i < R; i++) {
		cin >> str;
		for (int j = 0; j < C; j++) {
			arr[i][j] = (int)str.at(j) - 48;
		}
	}

	BFS(0, 0);
	cout << dp[R - 1][C - 1] + 1 << endl;
}