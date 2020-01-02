#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int a, b, c, k;
	k = N + 1;
	a = 1;
	b = 1;
	c = 1;
	int min = (a * b * c) + (a * c * k);
	int max = (b * c * k) + (a * b * k);
	cout << 3 << endl;
	cout << a << " " << b << " "  << c  << " "<< k;
}