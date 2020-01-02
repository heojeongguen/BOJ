#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int maxSize = -1;
unsigned long long dp[51][51];
int main() {
	int r1, r2, c1, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	r1 += 5000;
	c1 += 5000;
	r2 += 5000;
	c2 += 5000;
	unsigned long long data;
	int count = 1;
	while (true) {
		if (count > 10001) break;
		unsigned long long size = count - 1;
		unsigned long long data = count * count;
		unsigned long long r = 5000 + count / 2;
		unsigned long long c = 5000 + count / 2;
		if (r <= r2 && r >= r1 && c >= c1 && c <= c2) {
			dp[abs(r - r1) + 1][abs(c - c1) + 1] = data;
			maxSize = max(maxSize, int(log10(data) + 1));
		}

		for (int i = 0; i < size; i++) {
			c--;
			data--;
			if (r <= r2 && r >= r1 && c >= c1 && c <= c2) {
				dp[abs(r - r1) + 1][abs(c - c1) + 1] = data;
				maxSize = max(maxSize,int(log10(data) + 1));
			}
		}
		for (int i = 0; i < size; i++) {
			r--;
			data--;
			if (r <= r2 && r >= r1 && c >= c1 && c <= c2) {
				dp[abs(r - r1) + 1][abs(c - c1) + 1] = data;
				maxSize = max(maxSize, int(log10(data) + 1));
				//cout << "r : " << r << " c : " << c << endl;
			}
		}
		for (int i = 0; i < size; i++) {
			c++;
			data--;
			if (r <= r2 && r >= r1 && c >= c1 && c <= c2) {
				dp[abs(r - r1) + 1][abs(c - c1) + 1] = data;
				maxSize = max(maxSize, int(log10(data) + 1));
				//cout << "r : " << r << " c : " << c << endl;
			}
		}
		for (int i = 0; i < size - 1; i++) {
			r++;
			data--;
			if (r <= r2 && r >= r1 && c >= c1 && c <= c2) {
				dp[abs(r - r1) + 1][abs(c - c1) + 1] = data;
				maxSize = max(maxSize, int(log10(data) + 1));
				//cout << "r : " << r << " c : " << c << endl;
			}
		}
		count += 2;
	}

	for (int i = 1; i <= abs(r2 - r1) + 1; i++) {
		for (int j = 1 ; j <= abs(c2 - c1) + 1; j++) {
			cout.width(maxSize);
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

}