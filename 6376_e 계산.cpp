#include <iostream>

using namespace std;

double fac(int n) {
	double ret = 1;
	for (int i = n; i >= 1; i--) {
		ret *= i;
	}
	return 1/ret;
}

int main() {
	cout << "n e" << endl;
	cout << "- -----------" << endl;
	for (int i = 0; i <= 9; i++) {
		double e = 0;
		for (int j = 0; j <= i; j++) {
			e += fac(j);
		}
		cout.precision(10);
		cout << i << " " << e;
		if (i == 8) cout << 0;
		cout << endl;

	}
}