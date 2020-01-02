#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long GCD(unsigned long long a, unsigned long long b) {
	if (b < 0) return -1;

	while (b > 0) {
		int tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}

int main() {
	unsigned long long T, head, tail, great, lesat;
	unsigned long long gcd, glm;
	unsigned long long tmp;
	cin >> T;
	while (T--) {
		cin >> head >> tail;
		gcd = GCD(tail, head);
		head = head / gcd;
		tail = tail / gcd;
		while (head != 1) {

			tmp = (int)(tail / head) + 1;
			if (tail > tmp) {
				gcd = GCD(tail, tmp);
				glm = tail * tmp / gcd;
			}
			else {
				gcd = GCD(tmp, tail);
				glm = tail * tmp / gcd;
			}
		
			head = (head * glm / tail - glm/tmp);
			tail = glm;
			gcd = GCD(tail, head);
			head = head / gcd;
			tail = tail / gcd;
		}
		cout << tail << endl;
	}
}