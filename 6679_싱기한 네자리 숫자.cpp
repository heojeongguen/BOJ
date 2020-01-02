#include <iostream>
//int decimal = 41;   // 10����
//int octal = 041;  //  8����
//int hexadecimal = 0x41; // 16����
using namespace std;

int main() {
	for (int i = 1000; i <= 9999; i++) {
		int deci = i;
		int dec = 0;
		int hex = 0;
		int oct = 0;
		while (deci > 0) {
			hex += deci % 16;
			deci /= 16;
		}
		deci = i;

		while (deci > 0) {
			oct += deci % 12;
			deci /= 12;
		}
		deci = i;

		while (deci > 0) {
			dec += deci % 10;
			deci /= 10;
		}

		if (hex == oct && oct == dec) {
			cout << i << endl;
		}
	}
}