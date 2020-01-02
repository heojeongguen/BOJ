#include <iostream>
#include <cstdio>
using namespace std;

int arr[22][22];
int dice[4][3];
pair<int, int> dxdy[5] = { {0,0}, {0,1},{0,-1},{-1,0},{1,0} };
void RR() {
	int tmp1 = dice[1][0];
	int tmp2 = dice[1][1];
	int tmp3 = dice[1][2];
	int tmp4 = dice[3][1];
	dice[1][0] = tmp4;
	dice[1][1] = tmp1;
	dice[1][2] = tmp2;
	dice[3][1] = tmp3;
}

void LL() {
	int tmp1 = dice[1][0];
	int tmp2 = dice[1][1];
	int tmp3 = dice[1][2];
	int tmp4 = dice[3][1];
	dice[1][0] = tmp2;
	dice[1][1] = tmp3;
	dice[1][2] = tmp4;
	dice[3][1] = tmp1;
}

void UU() {
	int tmp1 = dice[0][1];
	int tmp2 = dice[1][1];
	int tmp3 = dice[2][1];
	int tmp4 = dice[3][1];
	dice[0][1] = tmp2;
	dice[1][1] = tmp3;
	dice[2][1] = tmp4;
	dice[3][1] = tmp1;
}

void DD() {
	int tmp1 = dice[0][1];
	int tmp2 = dice[1][1];
	int tmp3 = dice[2][1];
	int tmp4 = dice[3][1];
	dice[0][1] = tmp4;
	dice[1][1] = tmp1;
	dice[2][1] = tmp2;
	dice[3][1] = tmp3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, x, y, K;
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	//dice[0][1] = 2;
	//dice[1][1] = 1;
	//dice[2][1] = 5;
	//dice[3][1] = 6;
	//dice[1][0] = 4;
	//dice[1][2] = 3;

	int direc;
	for (int i = 0; i < K; i++) {
		cin >> direc;
		int nextX = x + dxdy[direc].first;
		int nextY = y + dxdy[direc].second;

		if (nextX >= N || nextX < 0 || nextY >= M || nextY < 0) continue;
		else {
			x = nextX;
			y = nextY;
			if (direc == 1) RR();
			else if (direc == 2) LL();
			else if (direc == 3) UU();
			else if (direc == 4) DD();

			if (arr[x][y] == 0) {
				arr[x][y] = dice[3][1];
			}
			else {
				dice[3][1] = arr[x][y];
				arr[x][y] = 0;
			}
			cout << dice[1][1] << "\n";
		}

		
	}
	return 0;
}