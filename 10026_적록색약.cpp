#include <iostream>
#include <string>
using namespace std;

char A[101][101];
char B[101][101];
int N;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visit[101][101];
bool visit2[101][101];
void BFS1(int nowR, int nowC, char tag) {

	visit[nowR][nowC] = true;

	for (int i = 0; i < 4; i++) {
		int nextR = nowR + dx[i];
		int nextC = nowC + dy[i];
		if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N || visit[nextR][nextC] == true) continue;
		if (A[nextR][nextC] == tag) {
			BFS1(nextR, nextC, tag);
		}
	}
}


void BFS2(int nowR, int nowC, char tag) {

	visit2[nowR][nowC] = true;

	for (int i = 0; i < 4; i++) {
		int nextR = nowR + dx[i];
		int nextC = nowC + dy[i];
		if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N || visit2[nextR][nextC] == true) continue;
		if (B[nextR][nextC] == tag) {
			BFS2(nextR, nextC, tag);
		}
	}
}
int main() {
	string str;
	cin >> N;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			A[i][j] = str[j];
			B[i][j] = str[j];
			if (B[i][j] == 'G') B[i][j] = 'R';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == false) {
				BFS1(i, j, A[i][j]);
				cnt1++;
			}
			if (visit2[i][j] == false) {
				BFS2(i, j, B[i][j]);
				cnt2++;
			}
		}
	}
	cout << cnt1 << " " << cnt2 << endl;
}