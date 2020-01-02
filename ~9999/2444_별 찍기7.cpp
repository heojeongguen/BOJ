#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int star = 1;
	for (int i = N; i > 1; i--) {
		for (int j = 1; j < i; j++) {
			cout << " ";
		}
		for (int j = 0; j < star; j++) {
			cout << "*";
		}
		star += 2;
		cout << endl;

	}
	for (int i = N; i > 0; i--) {
		for (int j = 0; j < N - (i); j++) {
			cout << " ";
		}
		for (int j = 0; j < 2 * i - 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
}