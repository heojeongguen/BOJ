#include <iostream>

using namespace std;

int main() {
	int N, K;
	unsigned long long ans = 1;
	cin >> N >> K;
	for (int i = N; i > N - K; i--) {
		ans *= i;
	}
	for (int i = K; i >= 1; i--) {
		ans /= i;
	}
	cout << ans << endl;
}