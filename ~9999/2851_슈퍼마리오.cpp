#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int D;
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		cin >> D;
		if (ans + D > 100) {
			if (ans + D - 100 > 100 - ans) {
				cout << ans << endl;
				return 0;
			}
			else if (ans + D - 100 < 100 - ans) {
				cout << ans + D << endl;
				return 0;
			}
			else {
				cout << ans + D << endl;
				return 0;
			}
			break;
		}
		else {
			ans += D;
		}
	}

	cout << ans << endl;
}