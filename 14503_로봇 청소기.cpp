#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int r, c;

int R, C, D;
int arr[51][51];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt = 0;
void fuc_a();
int direc = 0;

void clearNow() {
	arr[R][C] = 1;
	cnt++;
	direc = 0;
	fuc_a();

	
}
// 0 À§
// 1 ¿À¸¥Á·
// 2 ¹Ø
// 3 ¿ÞÂÊ
void fuc_a() {
	if (direc == 4) {
		if (D == 0) {
			R++;
			if (arr[R][C] == -1 || R >= r) return;
			else {
				direc = 0;
				fuc_a();
			}
		}
		else if (D == 1) {
			C--;
			if (arr[R][C] == -1 || c < 0) return;
			else {
				direc = 0;
				fuc_a();
			}
		}
		else if (D == 2) {
			R--;
			if (arr[R][C] == -1 || R < 0) return;
			else {
				direc = 0;
				fuc_a();
			}
		}
		else if (D == 3) {
			C++;
			if (arr[R][C] == -1 || C >= c) return;
			else {
				direc = 0;
				fuc_a();
			}
		}
	}
	else {
		direc++;

		if (D == 0) {
			if (C - 1 >= 0 && arr[R][C - 1] == 0) {
				D = 3;
				C--;
				clearNow();
				return;
			}
			D = 3;
			

			fuc_a();
		}
		else if (D == 1) {

			if (R - 1 >= 0 && arr[R - 1][C] == 0) {
				D = 0;
				R--;
				clearNow();
				return;
			}
			D = 0;
			fuc_a();
		
		}
		else if (D == 2) {

			if (C + 1 < c && arr[R][C+1] == 0) {
				D = 1;
				C++;
				clearNow();
				return;
			}
			D = 1;
			fuc_a();
		
		}

		else if (D == 3) {
			if (R + 1 < r && arr[R + 1][C] == 0) {
				D = 2;
				R++;
				clearNow();
				return;
			}
			D = 2;
			fuc_a();

		}
	}
}

	int main() {
		cin >> r >> c;
		cin >> R >> C >> D;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 1) arr[i][j] = -1;
			}
		}
		clearNow();
		cout << cnt << endl;

	}