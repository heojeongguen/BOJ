#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A, B;
	int AA = 0, BB = 0;
	cin >> A >> B;
	for (int i = 100, j = 1; i >= 1; i /= 10, j *= 10) {
		int a = A / i;
		int b = B / i;
		AA += a * j;
		BB += b * j;
		A -= a * i;
		B -= b * i;
	}
	cout << max(AA, BB) << endl;
}