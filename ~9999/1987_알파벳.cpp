#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int arr[20][20];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int R, C;
int mmax = 0;
bool visit[26];

// 2중 테이블을 만들어서 해도 되겠지만 어렵다.
// visit[26] 이라는 알파벳 정보 dp만 을 이용해도 된다.
void DFS(int nowR, int nowC, int cnt) {
	int id = arr[nowR][nowC];
	visit[id] = true;
	mmax = max(mmax, cnt);
	bool find;
	for (int i = 0; i < 4; i++) {
		int nextR = nowR + dx[i];
		int nextC = nowC + dy[i];
		int nextID = arr[nextR][nextC];
		if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
		if (visit[nextID] != true) {
		// 현재기준 사용
		visit[nextID] = true;
		DFS(nextR, nextC, cnt + 1);
		// 자원 반환 
		visit[nextID] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> str;
		for (int j = 0; j < C; j++) {
			arr[i][j] = (int)str[j] - 65;
		}
	}
	DFS(0, 0, 1);
	cout << mmax  << "\n";
}