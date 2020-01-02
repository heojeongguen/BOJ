#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int mmax = 0;
	int A, B, C, D;

	for (int i = 0; i < 2; i++) {
		cin >> A >> B >> C >> D;
		mmax = max(mmax, A + B + C + D);
	}
	cout << mmax << endl;
}