#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A, B, C, D, P;
	cin >> A >> B >> C >> D >> P;
	int AA = A * P;
	int BB;
		if (P - C > 0) {
			BB = B + (P - C)*D;
		}
		else {
			BB = B;
		}
	cout << min(AA, BB) << endl;
}