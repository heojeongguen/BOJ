#include  <iostream>

using namespace std;
// 피사노 주기를 이용한 풀이
// mod = 
long long mod = 1000000;
long long modd = 100000;
int arr[1500001];
int main() {
	long long n;
	long long ans;
	cin >> n;
	n = n % (15 * modd);
	long long prev = 1;
	long long pprev = 0;
	if (n == 0) {
		cout << 1 << endl;
		return 0;
	}
	else if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	else if (n == 2) {
		cout << 1 << endl;
		return 0;
	}
	else {
		for (int i = 2; i < 15 * mod / 10; i++) {
			if (i > n) {
				break;
			}
			arr[i] = (prev + pprev) % mod;
			pprev = prev;
			prev = arr[i];
		}
		cout << arr[n % (15 * modd)] << endl;
	}
}