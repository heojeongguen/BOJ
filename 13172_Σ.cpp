#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// arr[1] = 어떤수의 2^1 = 2 승 
// arr[2] = 어떤수의 2^2 = 4 승
unsigned long long arr[60];
unsigned long long DIV = 1000000007;

// 어떤수의 x 승을 리턴
unsigned long long fuc(unsigned long long x) {
	int size = log2(x);
	unsigned long long tmp = 1;
	for (int i = 1; i <= size; i++) {
		tmp *= 2;
	}
	if (pow(2, size) == x && size < 60) {
		return arr[size];
	}
	else if (x == 1) {
		return arr[0];
	}
	else if (x == 0) {
		return 1;
	}

	return ((fuc(tmp) % DIV) * (fuc(x - tmp) % DIV)) % DIV;
}


// 최대공약수
int GCM(unsigned long long x, unsigned long long y)
{
	int n;
	while (1) {
		n = x % y;
		if (n == 0) return y;
		x = y;
		y = n;
	}
}

int main() {
	unsigned long long M, N = 0, S = 0, data1, data2;
	unsigned long long ans = 0;
	cin >> M;
	while (M--) {
		cin >> N >> S;

		// 배열초기화
		for (int i = 0; i < 60; i++) {
			arr[i] = 0;
		}

		// 최대공약수로 기약분수로 만들어 준다.
		unsigned long long gcm;
		gcm = GCM(N, S);
		N /= gcm;
		S /= gcm;

		// N의 DIV - 2 승을 구한다
		arr[0] = N % DIV;
		for (int i = 1; i < 60; i++) {
			arr[i] = ((arr[i - 1] % DIV)* (arr[i - 1] % DIV)) % DIV;
		}
		ans += (S * fuc(DIV - 2)) % DIV;
	}

	// 출력
	cout << ans << endl;
}