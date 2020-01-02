#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

class info {
public:
	int num;
	int r;
	int c;
	info(int num, int r, int c) {
		this->r = r;
		this->c = c;
		this->num = num;
	}
	
};

using namespace std;
vector<info> CCTV;

void cctv_1(vector<vector<int> > vec, int r, int c, int cctvNum);
void cctv_2(vector<vector<int> > vec, int r, int c, int cctvNum);
void cctv_3(vector<vector<int> > vec, int r, int c, int cctvNum);
void cctv_4(vector<vector<int> > vec, int r, int c, int cctvNum);
void cctv_5(vector<vector<int> > vec, int r, int c, int cctvNum);

int R, C;
int arr[8][8];
int mmin = 100000;


void next(int cctvNum, vector<vector<int> > vec) {
	if (cctvNum == CCTV.size()) {
		int tmp = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (vec[i][j] == 0) tmp++;
			}
		}
		mmin = min(tmp, mmin);
	}
	else {
		if (CCTV[cctvNum].num == 1) cctv_1(vec, CCTV[cctvNum].r, CCTV[cctvNum].c, cctvNum + 1);
		else if (CCTV[cctvNum].num == 2) cctv_2(vec, CCTV[cctvNum].r, CCTV[cctvNum].c, cctvNum + 1);
		else if (CCTV[cctvNum].num == 3) cctv_3(vec, CCTV[cctvNum].r, CCTV[cctvNum].c, cctvNum + 1);
		else if (CCTV[cctvNum].num == 4) cctv_4(vec, CCTV[cctvNum].r, CCTV[cctvNum].c, cctvNum + 1);
		else if (CCTV[cctvNum].num == 5) cctv_5(vec, CCTV[cctvNum].r, CCTV[cctvNum].c, cctvNum + 1);

	}
}

void cctv_1(vector<vector<int> > vec,int r, int c, int cctvNum) {
	vector<vector<int> > tmp = vec;
	for (int i = r; i < R; i++) {
		if (tmp[i][c] == 6) break;
		else tmp[i][c] = 7;
	}
	next(cctvNum, tmp);

	tmp = vec;
	for (int i = r; i >= 0; i--) {
		if (tmp[i][c] == 6) break;
		else tmp[i][c] = 7;
	}
	next(cctvNum, tmp);

	tmp = vec;
	for (int i = c; i < C; i++) {
		if (tmp[r][i] == 6) break;
		else tmp[r][i] = 7;
	}
	next(cctvNum, tmp);

	tmp = vec;
	for (int i = c; i >= 0; i--) {
		if (tmp[r][i] == 6) break;
		else tmp[r][i] = 7;
	}
	next(cctvNum, tmp);

	return;
}

// cctv 2
void cctv_2(vector<vector<int> > vec, int r, int c, int cctvNum) {
	vector<vector<int> > tmp = vec;
	for (int i = r; i < R; i++) {
		if (tmp[i][c] == 6) break;
		else tmp[i][c] = 7;
	}
	for (int i = r; i >= 0; i--) {
		if (tmp[i][c] == 6) break;
		else tmp[i][c] = 7;
	}
	next(cctvNum, tmp);

	tmp = vec;
	for (int i = c; i < C; i++) {
		if (tmp[r][i] == 6) break;
		else tmp[r][i] = 7;
	}
	for (int i = c; i >= 0; i--) {
		if (tmp[r][i] == 6) break;
		else tmp[r][i] = 7;
	}
	next(cctvNum, tmp);

	return;
}

// cctv 3
void cctv_3(vector<vector<int> > vec, int r, int c, int cctvNum) {
	vector<vector<int> > tmp = vec;
	for (int i = r; i >= 0; i--) {
		if (tmp[i][c] == 6) break;
		else tmp[i][c] = 7;
	}
	for (int i = c; i < C; i++) {
		if (tmp[r][i] == 6) break;
		else tmp[r][i] = 7;
	}
	next(cctvNum, tmp);

	tmp = vec;
	for (int i = c; i < C; i++) {
		if (tmp[r][i] == 6) break;
		else tmp[r][i] = 7;
	}
	for (int i = r; i < R; i++) {
		if (tmp[i][c] == 6) break;
		else tmp[i][c] = 7;
	}
	next(cctvNum, tmp);

	tmp = vec;
	for (int i = r; i < R; i++) {
		if (tmp[i][c] == 6) break;
		else tmp[i][c] = 7;
	}
	for (int i = c; i >= 0; i--) {
		if (tmp[r][i] == 6) break;
		else tmp[r][i] = 7;
	}
	next(cctvNum, tmp);

	tmp = vec;
	for (int i = c; i >= 0; i--) {
		if (tmp[r][i] == 6) break;
		else tmp[r][i] = 7;
	}
	for (int i = r; i >= 0; i--) {
		if (tmp[i][c] == 6) break;
		else tmp[i][c] = 7;
	}
	next(cctvNum, tmp);

	return;
}

// cctv 4
void cctv_4(vector<vector<int> > vec, int r, int c, int cctvNum) {
	vector<vector<int> > tmp = vec;

	// LL
	for (int i = c; i >= 0; i--) {
		if (tmp[r][i] == 6) break;
		else tmp[r][i] = 7;
	}
	// UU
	for (int i = r; i >= 0; i--) {
		if (tmp[i][c] == 6) break;
		else tmp[i][c] = 7;
	}
	// RR
	for (int i = c; i < C; i++) {
		if (tmp[r][i] == 6) break;
		else tmp[r][i] = 7;
	}
	next(cctvNum, tmp);

	tmp = vec;
	// UU
	for (int i = r; i >= 0; i--) {
		if (tmp[i][c] == 6) break;
		else tmp[i][c] = 7;
	}
	// RR
	for (int i = c; i < C; i++) {
		if (tmp[r][i] == 6) break;
		else tmp[r][i] = 7;
	}
	// DD
	for (int i = r; i < R; i++) {
		if (tmp[i][c] == 6) break;
		else tmp[i][c] = 7;
	}
	next(cctvNum, tmp);

	tmp = vec;
	// RR
	for (int i = c; i < C; i++) {
		if (tmp[r][i] == 6) break;
		else tmp[r][i] = 7;
	}
	// DD
	for (int i = r; i < R; i++) {
		if (tmp[i][c] == 6) break;
		else tmp[i][c] = 7;
	}
	// LL
	for (int i = c; i >= 0; i--) {
		if (tmp[r][i] == 6) break;
		else tmp[r][i] = 7;
	}
	next(cctvNum, tmp);

	tmp = vec;
	// DD
	for (int i = r; i < R; i++) {
		if (tmp[i][c] == 6) break;
		else tmp[i][c] = 7;
	}
	// LL
	for (int i = c; i >= 0; i--) {
		if (tmp[r][i] == 6) break;
		else tmp[r][i] = 7;
	}
	// UU
	for (int i = r; i >= 0; i--) {
		if (tmp[i][c] == 6) break;
		else tmp[i][c] = 7;
	}
	next(cctvNum, tmp);

	return;
}

void cctv_5(vector<vector<int> > vec, int r, int c, int cctvNum) {
	vector<vector<int> > tmp = vec;
	// LL
	for (int i = c; i >= 0; i--) {
		if (tmp[r][i] == 6) break;
		else tmp[r][i] = 7;
	}
	// UU
	for (int i = r; i >= 0; i--) {
		if (tmp[i][c] == 6) break;
		else tmp[i][c] = 7;
	}
	// RR
	for (int i = c; i < C; i++) {
		if (tmp[r][i] == 6) break;
		else tmp[r][i] = 7;
	}
	// DD
	for (int i = r; i < R; i++) {
		if (tmp[i][c] == 6) break;
		else tmp[i][c] = 7;
	}
	next(cctvNum, tmp);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;
	vector<vector<int> > vec(R, vector<int>(C, 0));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> vec[i][j];
			if (vec[i][j] != 0 && vec[i][j] != 6) {
				info a(vec[i][j], i, j);
				CCTV.push_back(a);
			}
		}
	}
	next(0, vec);

	cout << mmin << endl;
	return 0;
}