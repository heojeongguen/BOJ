#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	int star = N - 1;
	for (int i = 0; i < N ; i++) {
		for (int j = 0; j < (N - 1) - star; j++) {
			cout << " ";
		}
		for (int j = 0; j < 2 * star + 1; j++) {
			cout << "*";
		}
		cout << "\n";
		star--;
	}
	star = 1;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < (N - 1) - star; j++) {
			cout << " ";
		}
		for (int j = 0; j < 2 * star + 1; j++) {
			cout << "*";
		}
		cout << "\n";
		star++;
	}
}