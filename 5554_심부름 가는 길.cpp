#include <iostream>

using namespace std;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	int mil;
	mil = A + B + C + D;
	cout << mil / 60 << endl << mil % 60 << endl;
}