#include <iostream>

using namespace std;

double chance[5];
double win, lose, draw;
int dp[21][21][21];
int getRank(int point) {
	if (point >= 1000 && point <= 1499) return 0;
	else if (point >= 1500 && point <= 1999) return 1;
	else if (point >= 2000 && point <= 2499) return 2;
	else if (point >= 2500 && point <= 2999) return 3;
	else if (point >= 3000 && point <= 3499) return 4;
}

double myFuc(double a, int b) {
	double ret = 1.0;
	double tmp = a;
	while (b > 0) {
		if (b % 2 == 1) {
			ret *= tmp;
		}
		tmp *= tmp;
		b /= 2;
	}
	return ret;
}

int fuc(int w, int l, int d) {
	if (w < 0 || l < 0 || d < 0) return 0;

	if (dp[w][l][d] != -1) return dp[w][l][d];

	if (w == 0 && l == 0 && d == 0) return 1;

	int ret = fuc(w - 1, l, d) + fuc(w, l - 1, d) + fuc(w, l, d - 1);
	dp[w][l][d] = ret;
	return dp[w][l][d];
}

int main() {
	ios::sync_with_stdio(false);
	cin >> win >> lose >> draw;
	cout.precision(8);
	for (int i = 0; i <= 20; i < i++) {
		for (int j = 0; j <= 20 ; j++) {
			for (int z = 0; z <= 20; z++) {
				dp[i][j][z] = -1;
			}
		}
	}
	for (int i = 0; i <= 20; i < i++) {
		for (int j = 0; j <= 20 - i; j++) {
			int draw_cnt = 20 - i - j;
			chance[getRank(2000 + i * 50 - j * 50)] += (myFuc(win, i) * myFuc(lose, j) * myFuc(draw, draw_cnt)) * fuc(i,j,20-i-j);
		}
	}
	for (int i = 0; i < 5; i++) {
		cout << fixed << chance[i] << endl;
	}
}
