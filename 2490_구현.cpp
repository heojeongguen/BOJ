#include <iostream>

using namespace std;

int main() {
	int data;
	int count;
	char ans;
	for (int i = 1; i <= 3; i++) {
		count = 0;
		for (int j = 1; j <= 4; j++) {
			cin >> data;
			if (data == 0) {
				count++;
			}
		}
		if (count == 1) {
			ans = 'A';
		}
		else if (count == 2) {
			ans = 'B';
		}
		else if (count == 3) {
			ans = 'C';
		}
		else if (count == 4) {
			ans = 'D';
		}
		else {
			ans = 'E';
		}
		cout << ans << endl;
	}
}