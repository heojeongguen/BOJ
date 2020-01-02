#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int R, C;
int A[8][8];
int AA[8][8];
bool arr[8][8][8][8][8][8];

vector <pair<int, int>> vec;
queue< pair<int, int>> que;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0, 0,-1,1 };
int cnt ;
int mmax ;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cnt = 0;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> A[i][j];
			if (A[i][j] == 0) {
				vec.push_back(make_pair(i, j));
			}
		}
	}
	
	int zero = vec.size();

	for (int i = 0; i<vec.size()-2; i++) {
		for (int j = i + 1; j < vec.size() - 1; j++) {
			for (int z = j + 1; z < vec.size(); z++) {
				cnt = zero;
				for (int ii = 0; ii < R; ii++) {
					for (int jj = 0; jj < C; jj++) {
						AA[ii][jj] = A[ii][jj];
						if (AA[ii][jj] == 2) que.push(make_pair(ii, jj));
					}
				}
				

				AA[vec[i].first][vec[i].second] = 1;
				AA[vec[j].first][vec[j].second] = 1;
				AA[vec[z].first][vec[z].second] = 1;
				cnt -= 3;
			
				while (!que.empty()) {
					int nowR = que.front().first;
					int nowC = que.front().second;
					que.pop();
				
					for (int ii = 0; ii < 4; ii++) {
						int nextR = nowR + dx[ii];
						int nextC = nowC + dy[ii];
						if (nextR >= R || nextR < 0 || nextC >= C || nextC < 0) continue;
						if (AA[nextR][nextC] == 0) {
							AA[nextR][nextC] = 2;
							que.push(make_pair(nextR, nextC));
							cnt--;
						}
					}
				}
				mmax = max(mmax, cnt);
			}
		}
	}
	cout << mmax << endl;
}