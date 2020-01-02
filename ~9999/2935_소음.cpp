#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string A, B;
	char oper;
	cin >> A >> oper >> B;
	int lenA = A.length();
	int lenB = B.length();
	if (oper == '*') {
		cout << 1;
		int len = lenA + lenB - 2;
		for (int i = 0; i < len; i++) {
			cout << 0;
		}
	}
	else {
		if (lenA == lenB) {
			cout << 2;
			for (int i = 0; i < lenA-1; i++) {
				cout << 0;
			}
		}
		else {
			int len = max(lenA, lenB);
			int llen = min(lenA, lenB);
			cout << 1;
			for (int i = 0; i < len -1; i++) {
				if (len - 1 - i == llen)cout << 1;
				else cout << 0;
			}
		}
	}
}