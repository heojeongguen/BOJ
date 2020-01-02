#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long DIV = 2147483647;

unsigned long long fac(int x,int xx) {
	unsigned long long ans = 1;
	for (int i = x; i >= xx; i--) {
		ans = (ans * i) % DIV;
	}
	return ans;
}


//	 제곱근
// 라이브러리보다 빠름
long pow(unsigned long long a, unsigned long long b) {
	unsigned long long ret = 1;
	unsigned long long aa = a;
	while (b > 0) {
		if (b % 2 == 1) ret = ret * aa  % DIV;
		b = b / 2;
		aa = (aa * aa) % DIV;
	}
	return ret;
}



int main() {
	unsigned long long N, K;
	unsigned long long head, tail, ans = 0;
	while (true) {

		cin >> N >> K;
		if (N == 0 && K == 0) {
			break;
		}
		int index1;
		int index2;
		if (N - K + 1 > K) {
			index1 = N - K + 1;
			index2 = K;
		}
		else {
			index1 = K + 1;
			index2 = N - K;
		}
		head = fac(N ,index1) % DIV;
		tail = fac(index2, 1) % DIV;
		ans = head * pow(tail, DIV - 2) % DIV;
		cout << ans << endl;
	}

}