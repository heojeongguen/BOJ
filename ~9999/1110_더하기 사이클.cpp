#include <iostream>

using namespace std;

int main() {
	int N = -1, origin, temp,ans = 0;
	cin >> origin;
	while (origin != N) {
		if (N == -1) {
			N = origin;
		}
		if (N < 10) {
			N = N * 10 + N;
		}
		else {
			temp = (N / 10) + (N % 10);
			N = (N % 10) * 10 + (temp % 10);
		}
		ans++;
	}
	cout << ans << endl;
}