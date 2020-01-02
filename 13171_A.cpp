#include <iostream>
#include <cmath>
using namespace std;
unsigned long long const DIV = 1000000007;
unsigned long long arr[100001];
unsigned long long X, A;
unsigned long long fuc(unsigned long long x) {
	int size = log2(x);
	unsigned long long tmp = 1;
	for (int i = 1; i <= size; i++) {
		tmp *= 2;
	}
	if (pow(2,size) == x && size < 60) {
		return arr[size];
	}
	else if (x == 1) {
		return arr[0];
	}
	else if (x == 0) {
		return 1;
	}

	return ((fuc(tmp) % 
		) * (fuc(x - tmp) % DIV)) % DIV;
}

int main() {

	cin >> A >> X;
	unsigned long long size = log2(X);
	arr[0] = A % DIV;
	for (int i = 1; i < 60; i++) {
		arr[i] = ((arr[i - 1] % DIV)* (arr[i - 1] % DIV)) % DIV;
	}
	if (X == 0) {
		cout << 1 << endl;
	}
	else {
		cout << fuc(X) << endl;
	}
}