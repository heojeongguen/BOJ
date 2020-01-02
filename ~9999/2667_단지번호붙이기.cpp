#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int arr[26][26];
int dp[26][26];
int ans[626];
int N;
int cnt;
void BFS(int row, int col, int count){
	queue<pair<int, int>> que;
	que.push(make_pair(row, col));
	dp[row][col] = count;
	ans[count]++;
	while (!que.empty()) {
		queue<pair<int, int>> tmp;
		while (!que.empty()) {
			int r = que.front().first;
			int c = que.front().second;
			int tmpR;
			int tmpC;
			for (int i = 0; i < 4; i++) {
				tmpR = r;
				tmpC = c;
				if (i == 0) tmpR--;
				else if (i == 1) tmpR++;
				else if (i == 2) tmpC++;
				else if (i == 3) tmpC--;

				if (tmpR >= 0 && tmpR < N && tmpC >= 0 && tmpC < N && dp[tmpR][tmpC] == 0 && arr[tmpR][tmpC] == 1) {
					dp[tmpR][tmpC] = count;
					tmp.push(make_pair(tmpR, tmpC));
					ans[count]++;
				}
			}
			que.pop();
		}
		que = tmp;
	}
}


int main() {

	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			arr[i][j] = (int)str.at(j) - 48;
		}
	}
	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] == 0 && arr[i][j] == 1) {
				cnt++;
				BFS(i, j, cnt);
			}
		}
	}
	sort(ans + 1, ans + 1 + cnt);
	cout << cnt << endl;
	for (int i = 1; i <= cnt; i++) {
		cout << ans[i] << endl;
	}
}