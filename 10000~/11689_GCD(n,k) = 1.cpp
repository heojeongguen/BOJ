#include <iostream>

using namespace std;

// 오일러 피 함수를 이용한 N 과 n이하의 자연수와 서로소인 갯수 구하기


int main() {
	unsigned long long n;
	cin >> n;
	unsigned long long ans = n;

	// 결과 = n(1-1/P1)(1-1/P2)....(1-1/Pend);
	for (unsigned long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				// 제한 범위인 n를 i로 나누는이유는
				// 포함배제의 원리에서
				// 똑같은 수를 탐색하는 경우를 배제하기 위함이다.
				n /= i;
			}
			// 결과 *= (1-1/P);
			ans *= (1.0 - (1.0 / i));
		}
	}
	// 마지막남은 인수가 서로소이고, 제한범위에 의하여
	// 탐색되지 않았을때의 경우이다.
	if (n > 1) {
		ans *= (1.0 - (1.0 / n));
	}
	cout << ans << endl;
}