#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str;
	cin >> str;
	string tmp = "";
	unsigned long long A, B;
	for (int i = 0; i < str.size(); i++) {
		if (str.at(i) == ':') {
			A = stoll(tmp);
			tmp = "";
		}
		else {
			tmp += str.at(i);
		}
	}
	B = stoll(tmp);

	unsigned long long mini = min(A, B);
	int M;
	for (int i = mini; i >= 1; i--) {
		if (A % i == 0 && B % i == 0) {
			M = i;
			break;
		}
	}
	cout << A / M << ":" << B / M << endl;
}