#include <iostream>
#define endl '\n'
using namespace std;

int fibo[21];

int main() {
	fibo[0] = 0;
	fibo[1] = 1;

	int N; cin >> N;
	for (int i = 2; i <= N; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[N] << endl;
}