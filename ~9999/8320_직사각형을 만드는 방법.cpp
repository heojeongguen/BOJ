#include <iostream>

using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	int pow = 1;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) cnt++;
		if (i == pow) {
			cnt++;
			pow = (pow + 1)*(pow + 1);
		}
	}
	//
}