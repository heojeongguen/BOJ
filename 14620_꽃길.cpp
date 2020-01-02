/*
	백트래킹
	나중에 check;
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[11][11];
int N;
int mmin = 100000007;
void dfs(int r, int c, vector<vector<bool> > map, int point,int size) {
	if (point >= mmin) return;
	if (size == 15) {
		mmin = min(point, mmin);
	}

	if (r <= 0 || r >= N - 1 || c <= 0 || c >= N -1 ) return;
	

	if (c != N - 2) {
		dfs(r, c+1, map, point, size);
		if (map[r][c] == true) return;
		else if (map[r + 1][c] == true) return;
		else if (map[r - 1][c] == true) return;
		else if (map[r][c + 1] == true) return;
		else if (map[r][c - 1] == true) return;

		map[r][c] = true;
		map[r - 1][c] = true;
		map[r + 1][c] = true;
		map[r][c - 1] = true;
		map[r][c + 1] = true;
		point += (arr[r][c] + arr[r + 1][c] + arr[r - 1][c] + arr[r][c + 1] + arr[r][c - 1]);
		dfs(r, c + 1, map,point,size+5);
	}
	else {
		dfs(r+1, 1, map, point, size);
		if (map[r][c] == true) return;
		else if (map[r + 1][c] == true) return;
		else if (map[r - 1][c] == true) return;
		else if (map[r][c + 1] == true) return;
		else if (map[r][c - 1] == true) return;

		map[r][c] = true;
		map[r - 1][c] = true;
		map[r + 1][c] = true;
		map[r][c - 1] = true;
		map[r][c + 1] = true;
		point += (arr[r][c] + arr[r + 1][c] + arr[r - 1][c] + arr[r][c + 1] + arr[r][c - 1]);
		dfs(r + 1, 1, map, point, size + 5);
	}
	

	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	vector<vector<bool> > map(N, vector<bool>(N, false));

	dfs(1, 1, map,0,0);
	cout << mmin << "\n";
}