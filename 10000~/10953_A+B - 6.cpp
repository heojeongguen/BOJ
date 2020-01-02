#include <iostream>
#include <string>
using namespace std;

int main() {
	int T ,A, B;
	string str;
	cin >> T;
	while (T--) {
		cin >> str;
		A = (int)str.at(0) - 48;
		B = (int)str.at(2) - 48;
		cout << A + B << endl;
	}
}