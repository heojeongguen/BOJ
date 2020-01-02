#include <iostream>
#include <algorithm>
using namespace std;
int two = 0;
int five = 0;
int main() {
	unsigned long long N, ans = 0, tmp = 1;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int tmp = i;
		while (true) {
			if (tmp % 2 == 0) {
				two++;
				tmp /= 2;
				continue;
			}
			if (tmp % 5 == 0) {
				five++;
				tmp /= 5;
				continue;
			}
			break;
		}
	}
	cout << min(two,five) << endl;
}