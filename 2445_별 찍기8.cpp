#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	int star = 1;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < star; j++) {
			cout << "*";
		}
		for (int j = 0; j < ( 2 * N) - 2 * star; j++) {
			cout << " ";
		}
		for (int j = 0; j < star; j++) {
			cout << "*";
		}
		star++;
		cout << endl;
	}
	for (int i = 0; i < 2*N; i++) {
		cout << "*";
	}
	star = N - 1;
	cout << endl;
	for (int i = 0; i < N - 1; i++) {

		for (int j = 0; j < star; j++) {
			cout << "*";
		}
		for (int j = 0; j < (2 * N) - 2 * star; j++) {
			cout << " ";
		}
		for (int j = 0; j < star; j++) {
			cout << "*";
		}
		star--;
		cout << endl;
	}
}