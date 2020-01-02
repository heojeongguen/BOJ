#include <iostream>

using namespace std;

int main() {
	unsigned long long head = 1, tail = 1, count = 1, X;
	cin >> X;
	bool up = true;
	while (count != X) {
		if (up) {
			if (head - 1 == 0) {
				up = false;
				tail++;
				count++;
			}
			else {
				tail++;
				head--;
				count++;
			}
		}
		else {
			if (tail - 1 == 0) {
				up = true;
				head++;
				count++;
			}
			else {
				tail--;
				head++;
				count++;
			}
		}
	}
	cout << head << "/" << tail << endl;
}