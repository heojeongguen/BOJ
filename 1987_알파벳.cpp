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

// 2�� ���̺��� ���� �ص� �ǰ����� ��ƴ�.
// visit[26] �̶�� ���ĺ� ���� dp�� �� �̿��ص� �ȴ�.
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
		// ������� ���
		visit[nextID] = true;
		DFS(nextR, nextC, cnt + 1);
		// �ڿ� ��ȯ 
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