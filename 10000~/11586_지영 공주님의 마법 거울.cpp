#include <iostream>
using namespace std;
int N;
int mode;
char arr[101][101];

void print_1() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}

void print_2() {
	for (int i = 0; i < N; i++) {
		for (int j = N-1; j >=0; j--) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}

void print_3() {
	for (int i = N-1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> mode;
	if (mode == 1) print_1();
	else if (mode == 2) print_2();
	else print_3();
}