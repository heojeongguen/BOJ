#include <iostream>
#include <string>
using namespace std;

int main() {
	int A, B;
	string C;
	cin >> A >> B >> C;
	int last = (int)C.back() - '0';
	if (last % 2 == 0) {
		cout << A << endl;
	}
	else {
		cout << (A ^ B) << endl;
	}
	return 0;
}