#include <iostream>
#include <algorithm>
using namespace std;

char arr[11][11];
int ans = 11;

pair<int, int> x_y[4] = { {-1,0},{0,1},{1,0},{0,-1} };

void goFoward(int Rr, int Rc, int Br, int Bc, int direc, int cnt);
void dfs(int Rr, int Rc, int Br, int Bc, int prev_direc, int cnt);
void goRight(int &r, int &c, int &rr, int &cc);
void goUp(int &r, int &c, int &rr, int &cc);
void goLeft(int &r, int &c, int &rr, int &cc);
void goDown(int &r, int &c, int &rr, int &cc);

void dfs(int Rr, int Rc, int Br, int Bc, int prev_direc, int cnt) {
	if (prev_direc == -1) {
		for (int i = 0; i < 4; i++) {
			goFoward(Rr, Rc, Br, Bc, i, cnt + 1);
		}
	}
	else {
		for (int i = 0; i < 4; i++) {

			goFoward(Rr, Rc, Br, Bc, i, cnt + 1);
		}
	}
}
// 0 : 위
// 1 : 오른쪽
// 2 : 밑
// 3 : 위

void goUP(int &r, int &c, int &rr, int &cc) {
	while (true) {
		int nextR = r - 1;
		int nextC = c;
		if (arr[nextR][nextC] == '.' && (nextR != rr || nextC != cc)) {
			r = nextR;
			c = nextC;
			continue;
		}
		else if (arr[nextR][nextC] == 'O') {
			r = -1;
			c = -1;
			break;
		}
		else {
			break;
		}
	}
}
void goRight(int &r, int &c, int &rr, int &cc) {
	while (true) {
		int nextR = r;
		int nextC = c + 1;
		if (arr[nextR][nextC] == '.' && (nextR != rr || nextC != cc)) {
			r = nextR;
			c = nextC;
			continue;
		}
		else if (arr[nextR][nextC] == 'O') {
			r = -1;
			c = -1;
			break;
		}
		else break;
	}
}
void goDown(int &r, int &c, int &rr, int &cc) {
	while (true) {
		int nextR = r + 1;
		int nextC = c;
		if (arr[nextR][nextC] == '.' && (nextR != rr || nextC != cc)) {
			r = nextR;
			c = nextC;
			continue;
		}
		else if (arr[nextR][nextC] == 'O') {
			r = -1;
			c = -1;
			break;
		}
		else break;
	}
}
void goLeft(int &r, int &c, int &rr, int &cc) {
	while (true) {
		int nextR = r;
		int nextC = c - 1;
		if (arr[nextR][nextC] == '.' && (nextR != rr || nextC != cc)) {
			r = nextR;
			c = nextC;
			continue;
		}
		else if (arr[nextR][nextC] == 'O') {
			r = -1;
			c = -1;
			break;
		}
		else break;
	}
}

void goFoward(int Rr, int Rc, int Br, int Bc, int direc, int cnt) {
	int Rr_st = Rr;
	int Rc_st = Rc;
	int Br_st = Br;
	int Bc_st = Bc;

	if (cnt > 10) return;

	bool R_find = false;
	bool B_find = false;

	if (direc == 0) {
		if (Rr < Br) {

			goUP(Rr, Rc, Br, Bc);
			goUP(Br, Bc, Rr, Rc);


		}
		else {
			goUP(Br, Bc, Rr, Rc);
			goUP(Rr, Rc, Br, Bc);

		}
	}
	else if (direc == 1) {
		if (Rc > Bc) {
			goRight(Rr, Rc, Br, Bc);
			goRight(Br, Bc, Rr, Rc);
			
		}
		else {
			goRight(Br, Bc, Rr, Rc);
			goRight(Rr, Rc, Br, Bc);
			
		}
	}
	else if (direc == 2) {
		if (Rr > Br) {
			goDown(Rr, Rc, Br, Bc);
			goDown(Br, Bc, Rr, Rc);
		}
		else {
			goDown(Br, Bc, Rr, Rc);
			goDown(Rr, Rc, Br, Bc);
		}
	}
	else if (direc == 3) {
		if (Rc < Bc) {
			goLeft(Rr, Rc, Br, Bc);
			goLeft(Br, Bc, Rr, Rc);
		}
		else {
			goLeft(Br, Bc, Rr, Rc);
			goLeft(Rr, Rc, Br, Bc);
		}
	}
	if (Rr == -1 && Br != -1) {
		ans = min(ans, cnt);
	}
	else if (Rr != -1 && Br != -1) {
		if (Br != Br_st || Bc != Bc_st || Rr != Rr_st || Rc != Rc_st)
			dfs(Rr, Rc, Br, Bc, direc, cnt);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int Rr, Rc, Br, Bc;
	int R, C;
	char input;
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				Rr = i;
				Rc = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'B') {
				Br = i;
				Bc = j;
				arr[i][j] = '.';
			}
		}
	}

	dfs(Rr, Rc, Br, Bc, -1, 0);
	if (ans <= 10)
		cout << ans << "\n";
	else
		cout << -1 << "\n";
}