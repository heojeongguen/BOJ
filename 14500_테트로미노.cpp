#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501];
int R, C;
int mmax = -1;

//Á¤»ç°¢Çü
void check_yellow(int r, int c) {
	int tmp = 0;
	if (r + 1 <= R && c + 1 <= C) {
		tmp += arr[r][c];
		tmp += arr[r + 1][c];
		tmp += arr[r + 1][c + 1];
		tmp += arr[r][c + 1];
	}
	mmax = max(tmp, mmax);
}

// ÀÏÂ¥
void check_mint(int r, int c) {
	int tmp = 0;

	if (r + 3 <= R) {
		tmp = 0;
		tmp += arr[r][c];
		tmp += arr[r + 1][c];
		tmp += arr[r + 2][c];
		tmp += arr[r + 3][c];
		mmax = max(tmp, mmax);
	}

	if (c + 3 <= C) {
		tmp = 0;
		tmp += arr[r][c];
		tmp += arr[r][c + 1];
		tmp += arr[r][c + 2];
		tmp += arr[r][c + 3];
		mmax = max(tmp, mmax);
	}
}

void check_pink(int r, int c) {
	int tmp = 0;

	if (r + 1 <= R && c + 2 <= C) {
		tmp = 0;
		tmp += arr[r][c];
		tmp += arr[r][c + 1];
		tmp += arr[r][c + 2];
		tmp += arr[r + 1][c + 1];
		mmax = max(tmp, mmax);

	}

	// À§·Î »ÏÁ·
	if (r - 1 > 0 && c + 2 <= C) {
		tmp = 0;
		tmp += arr[r][c];
		tmp += arr[r][c + 1];
		tmp += arr[r][c + 2];
		tmp += arr[r - 1][c + 1];
		mmax = max(tmp, mmax);

	}

	// ¿À¸¥ÂÊÀ¸·Î »ÏÁ·
	if (r + 2 <= R && c + 1 <= C) {
		tmp = 0;
		tmp += arr[r][c];
		tmp += arr[r + 1][c];
		tmp += arr[r + 2][c];
		tmp += arr[r + 1][c + 1];
		mmax = max(tmp, mmax);

	}

	// ¿ÞÂÊÀ¸·Î »ÏÁ·
	if (r + 2 <= R && c - 1 > 0) {
		tmp = 0;
		tmp += arr[r][c];
		tmp += arr[r + 1][c];
		tmp += arr[r + 2][c];
		tmp += arr[r + 1][c - 1];
		mmax = max(tmp, mmax);

	}
}

void check_green(int r, int c) {
	int tmp = 0;

	// ¿ø·¡
	if (r + 2 <= R && c + 1 <= C) {
		tmp = 0;
		tmp += arr[r][c];
		tmp += arr[r + 1][c];
		tmp += arr[r + 1][c + 1];
		tmp += arr[r + 2][c + 1];
		mmax = max(tmp, mmax);
	}

	// ÁÂ¿ì ´ëÄª
	if (r + 2 <= R && c - 1 > 0) {
		tmp = 0;
		tmp += arr[r][c];
		tmp += arr[r + 1][c];
		tmp += arr[r + 1][c - 1];
		tmp += arr[r + 2][c - 1];
		mmax = max(tmp, mmax);
	}

	// È¸Àü
	if (r - 1 > 0 && c + 2 <= C) {
		tmp = 0;
		tmp += arr[r][c];
		tmp += arr[r][c + 1];
		tmp += arr[r - 1][c + 1];
		tmp += arr[r - 1][c + 2];
		mmax = max(tmp, mmax);
	}

	if (r - 1 > 0 && c - 2 > 0) {
		tmp = 0;
		tmp += arr[r][c];
		tmp += arr[r][c - 1];
		tmp += arr[r - 1][c - 1];
		tmp += arr[r - 1][c - 2];
		mmax = max(tmp, mmax);
	}
}

void check_orange(int r, int c) {
	int tmp = 0;

	// 1
	if (r + 2 <= R && c + 1 <= C) {
		tmp = 0;
		tmp += arr[r][c];
		tmp += arr[r + 1][c];
		tmp += arr[r + 2][c];
		tmp += arr[r + 2][c + 1];
		mmax = max(tmp, mmax);
	}

	// 2
	if (r + 2 <= R && c - 1 > 0) {
		tmp = 0;
		tmp += arr[r][c];
		tmp += arr[r + 1][c];
		tmp += arr[r + 2][c];
		tmp += arr[r + 2][c - 1];
		mmax = max(tmp, mmax);
	}

	// 3
	if (r - 1 > 0 && c + 2 <= C) {
		tmp = 0;
		tmp += arr[r][c];
		tmp += arr[r][c + 1];
		tmp += arr[r][c + 2];
		tmp += arr[r - 1][c + 2];
		mmax = max(tmp, mmax);
	}

	// 4
	if (r - 1 > 0 && c - 2 > 0) {
		tmp = 0;
		tmp += arr[r][c];
		tmp += arr[r][c - 1];
		tmp += arr[r][c - 2];
		tmp += arr[r - 1][c - 2];
		mmax = max(tmp, mmax);
	}

	// 5
	if (r + 2 <= R && c + 1 <= C) {
		tmp = 0;
		tmp += arr[r][c];
		tmp += arr[r][c + 1];
		tmp += arr[r + 1][c + 1];
		tmp += arr[r + 2][c + 1];
		mmax = max(tmp, mmax);
	}
	// 6
	if (r + 2 <= R && c - 1 > 0) {
		tmp = 0;
		tmp += arr[r][c];
		tmp += arr[r][c - 1];
		tmp += arr[r + 1][c - 1];
		tmp += arr[r + 2][c - 1];
		mmax = max(tmp, mmax);
	}

	// 7
	if (r - 1 > 0 && c + 2 <= C) {
		tmp = 0;
		tmp += arr[r][c];
		tmp += arr[r - 1][c];
		tmp += arr[r - 1][c + 1];
		tmp += arr[r - 1][c + 2];
		mmax = max(tmp, mmax);
	}
	// 8
	if (r - 1 > 0 && c - 2 > 0) {
		tmp = 0;
		tmp += arr[r][c];
		tmp += arr[r - 1][c];
		tmp += arr[r - 1][c - 1];
		tmp += arr[r - 1][c - 2];
		mmax = max(tmp, mmax);
	}
}

/*
if (r + 2 <= R && c + 1 <= C) {
	tmp = 0;

	mmax = max(tmp, mmax);
}
*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 0; j <= C; j++) {
			check_green(i, j);
			check_mint(i, j);
			check_orange(i, j);
			check_pink(i, j);
			check_yellow(i, j);
		}
	}
	cout << mmax << endl;
}