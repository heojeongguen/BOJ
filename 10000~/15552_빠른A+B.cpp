#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, A, B;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		cout << A + B << "\n";
	}
}