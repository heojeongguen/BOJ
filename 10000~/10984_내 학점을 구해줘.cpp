#include <iostream>
using namespace std;

int main() {
	int T, N;
	double cnt, grade, A, B;
	cin >> T;
	while (T--) {
		cnt = 0;
		grade = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A >> B;
			cnt += A;
			grade += (A * B);
		}
		cout.precision(2);
		cout << cnt << " " << grade / cnt << endl;
	}
}