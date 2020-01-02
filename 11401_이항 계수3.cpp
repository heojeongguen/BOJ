#include <iostream>

using namespace std;

long long DIV = 1000000007;

long long fac(int x) {
	long long ans = 1;
	for (int i = x; i >= 1; i--) {
		ans = (ans * i) % DIV;
	}
	return ans;
}


// pow 제곱근
// 라이브러리보다 빠름
long pow(long long a,long long b) {
	long long ret = 1;
	long long aa = a;
	while (b > 0) {
		if (b % 2 == 1) ret = (ret * aa)  % DIV;
		b = b / 2;
		aa = (aa * aa) % DIV;
	}
	return ret;
}



int main() {
	long long N, K;
	long long head, tail,ans = 0;
	cin >> N >> K;
	head = fac(N) % DIV;
	tail = (fac(N - K) % DIV) * (fac(K) % DIV) % DIV;

	ans = head * pow(tail, DIV - 2) % DIV;
	cout << ans  << endl;
	
}