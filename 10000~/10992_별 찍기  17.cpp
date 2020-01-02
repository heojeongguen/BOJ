#include <iostream>
#define endl '\n'
using namespace std;

int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		if (i == N - 1) {
			for (int j = 0; j < (N - 1) * 2 + 1 ; j++) {
				cout << "*";
			}
		}
		else {
			for (int j = 0; j < N - i - 1; j++) {
				cout << ' ';
			}
			cout << "*";
			for (int j = 0; j < (i - 1) * 2 + 1; j++) {
				cout << " ";
			}
			if (i != 0)
				cout << "*";
		}
		cout << endl;
	}
}
