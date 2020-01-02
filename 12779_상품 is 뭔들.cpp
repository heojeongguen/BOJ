#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
	// b는 a % b 지
	// 8 6
	// 6 * 1...2
	// 8 6
	// 6 2
	// 2 0
	while (b > 0) {
		long long tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long  a, b;
	cin >> a >> b;
	// 소인수 분해해서
	// 제곱수면 약수의 갯수가 홀수개 아닌교?
	//홀수개 1 , 4 ,9
	//짞수개 2 , 3, 5,6,7,8
	int cnt = 0;
	for (long long i = 1; i * i <= b; i++) {
		if (i * i > a) cnt++;
	}
	long long totalCnt = b - a;
	long long GCD = gcd(totalCnt, cnt);
	long long up = cnt / GCD;
	long long down = totalCnt / GCD;
	if (up == 0) cout << 0 << "\n";
	else cout << up << "/" << down << "\n";

}