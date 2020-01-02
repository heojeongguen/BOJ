#include <iostream>
#include <limits.h>
using namespace std;

double mmin = INT_MAX;

void check(double money, double gram) {
	double one_price = gram / money;
	if (mmin > 1000.0 / one_price) {
		mmin = 1000.0 / one_price;
	}
}

int main() {
	double N, money, gram;
	cin >> money >> gram;
	check(money, gram);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> money >> gram;
		check(money, gram);
	}
	cout << mmin << "\n";
}