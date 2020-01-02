#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int R, C, T;
pair<int, int> arr[51][51];
queue<pair<int, int>> que;
int time = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
pair<int, int> up;
pair<int, int> down;

void print_f() {
	cout << " ====== first ===========" << endl;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << arr[i][j].first << " ";
		}
		cout << endl;
	}
}


void print_s() {
	cout << "  ====== second ===========" << endl;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << arr[i][j].second << " ";
		}
		cout << endl;
	}
}
void bfs() {
	if (time == T) {
		int ans = 0;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				ans += arr[i][j].first;
			}
		}
		cout << ans + 2 << endl;
		return;
	}

	while (!que.empty()) {
		int nowR = que.front().first;
		int nowC = que.front().second;
		int tmp = arr[nowR][nowC].first / 5;
		que.pop();
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int nextR = nowR + dx[i];
			int nextC = nowC + dy[i];
			if (nextR <= 0 || nextC <= 0 || nextR > R || nextC > C) continue;
			if (arr[nextR][nextC].first == -1) continue;
			cnt++;	
			arr[nextR][nextC].second += tmp;
		}
		arr[nowR][nowC].first -= (tmp * cnt);
	}


	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (arr[i][j].first != -1) {
				arr[i][j].first += arr[i][j].second;
				arr[i][j].second = arr[i][j].first;
			}
		}
	}

	//print_f();
	//print_s();
	// 바람이분당~
	for (int i = 2; i <= C; i++) {
		if (arr[up.first][i-1].first == -1) arr[up.first][i].second = 0;
		else arr[up.first][i].second = arr[up.first][i-1].first;
	}

	for (int i = up.first - 1; i >= 1; i--) {
		arr[i][C].second = arr[i+1][C].first;
	}

	for (int i = C-1; i >= 1; i--) {
		arr[1][i].second = arr[1][i+1].first;
	}
	
	for (int i = 2; i < up.first; i++) {
		arr[i][1].second = arr[i-1][1].first;
	}

	// 아래 회전
	for (int i = 2; i <= C; i++) {
		if (arr[down.first][i - 1].first == -1) arr[down.first][i].second = 0;
		else arr[down.first][i].second = arr[down.first][i - 1].first;
	}

	for (int i = down.first + 1; i <= R; i++) {
		arr[i][C].second = arr[i - 1][C].first;
	}

	for (int i = C - 1; i >= 1; i--) {

		arr[R][i].second = arr[R][i + 1].first;
		
	}

	for (int i = R - 1; i > down.first; i--) {
		arr[i][1].second = arr[i + 1][1].first;
	}


	
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			arr[i][j].first = arr[i][j].second;
			if (arr[i][j].first > 0) que.push(make_pair(i, j));
			arr[i][j].second = 0;
		}
	}
	arr[up.first][up.second].first = -1;
	arr[down.first][down.second].first = -1;
	//print_f();
	time++;
	bfs();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C >> T;
	int D;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> D;
			arr[i][j].first = D;
			if (arr[i][j].first > 0) {
				que.push(make_pair(i, j));
			}
			else if (arr[i][j].first == -1) {
				if (up.first == 0) {
					up.first = i;
					up.second = j;
				}
				else {
					down.first = i;
					down.second = j;
				}
			}
		}
	}
	

	bfs();
}