#include <iostream>
using namespace std;
unsigned long long int arr[502][502];

int N;
unsigned long long M = -1;
int r, c;
bool fail = false;
unsigned long long total;

unsigned long long check_M() {
	unsigned long long tmp = 0;
	for (int i = 0; i < N; i++) {
		if (i == c) continue;
		else tmp += arr[r][i];
	}
	return tmp;
}

void check_row() {
	unsigned long long tmp = 0;
	for (int i = 0; i < N; i++) {
		tmp = 0;
		for (int j = 0; j < N; j++) {
			tmp += arr[j][i];
		}
		if (tmp != total) fail = true;
	}
}

void check_col() {
	unsigned long long tmp = 0;
	for (int i = 0; i < N; i++) {
		tmp = 0;
		for (int j = 0; j < N; j++) {
			tmp += arr[i][j];
		}
		if (tmp != total) fail = true;
	}
}

void check_right_down() {
	unsigned long long tmp = 0;
	for (int i = 0 , j = 0; i < N && j < N ; i++, j++) {
		 tmp += arr[i][j];
	}
	if (tmp != total) fail = true;
}

void check_right_up() {
	unsigned long long tmp = 0;
	for (int i = N-1, j = 0; i >= 0 && j < N; i--, j++) {
		tmp += arr[i][j];
	}
	if (tmp != total) fail = true;
}

unsigned long long find_total(int r) {
	unsigned long long tmp = 0;
	for (int i = 0; i < N; i++) {
		tmp += arr[r][i];
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				r = i;
				c = j;
			}
		}
	}
	if (r == 0) total = find_total(1);
	else total = find_total(0);

	unsigned long long M = total - check_M();
	arr[r][c] = M;

	check_col();
	check_row();
	check_right_down();
	check_right_up();
	if (fail || M <=0 ) cout << -1 << endl;
	else cout << M << endl;

}