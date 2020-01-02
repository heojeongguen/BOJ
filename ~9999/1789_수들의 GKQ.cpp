#include <iostream>

using namespace std;

int main() {
	unsigned long long S;
	cin >> S;
	unsigned long long a = 0;
	unsigned long long cnt = 1;
	while (a <= S) {
		a += cnt;
		cnt++;
	}
	cout << cnt - 2 << endl;
}