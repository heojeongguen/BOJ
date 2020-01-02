#include <iostream>
#include <string>
using namespace std;

int A[51][51];
int B[51][51];
int r, c;

void print() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << A[i][j];
		}
		cout << endl;
	}
}

int main() {
	string str;

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> str;
		for (int j = 0; j < c; j++) {
			A[i][j] = (int)str[j] - 48;
		}
	}
	for (int i = 0; i < r; i++) {
		cin >> str;
		for (int j = 0; j < c; j++) {
			B[i][j] = (int)str[j] - 48;
		}
	}
	int cnt = 0;
	for (int i = 0; i < r - 2; i++) {
		for (int j = 0; j < c - 2; j++) {
			if (A[i][j] == B[i][j]) continue;
			cnt++;
			for (int ii = i; ii < i + 3; ii++) {
				for (int jj = j; jj < j + 3; jj++) {
					if (A[ii][jj] == 0) A[ii][jj] = 1;
					else A[ii][jj] = 0;
				}
			}
		}
	}
	bool suc = true;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (A[i][j] != B[i][j]) suc = false;
		}
		if (!suc) break;
	}

	if (suc) {
		cout << cnt << endl;
	}
	else {
		cout << -1 << endl;
	}
}