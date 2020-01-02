#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	unsigned long long A, B;
	cin >> A >> B;
	int ans = 1;
	unsigned long long mini = min(A, B);
	unsigned long long D = 10000000;
	mini = min(D, mini);
	for (int i = 1; i <= mini; i++) {
		if (A % i == 0 && B % i == 0) {
			ans = i;
		}
	}
	for (int i = 0; i < ans; i++) {
		cout << 1;
	}
	cout << endl;
}