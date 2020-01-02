#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int star = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N - i; j++) {
			cout << " ";
		}
		for (int j = 0; j < star; j++) {
			cout << "*";
		}
		cout << "\n";
		star += 2;
	}
}