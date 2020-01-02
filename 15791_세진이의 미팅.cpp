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

long pow(long long a, long long b) {
	long long ret = 1;
	long long aa = a;
	while (b > 0) {
		if (b % 2 == 1) ret = ret * aa  % DIV;
		b = b / 2;
		aa = (aa * aa) % DIV;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	long long head, tail, ans = 0;
	cin >> N >> M;

	head = fac(N) % DIV;
	tail = (fac(N - M) % DIV) * (fac(M) % DIV) % DIV;

	cout << ans << endl;
}