#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	unsigned long long ans;
	unsigned long long M = 1;
	for (int i = 0; i < N; i++) {
		M *= 2;
	}
	M++;
	cout << M * M << endl;
}