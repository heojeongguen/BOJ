#include <iostream>
using namespace std;

unsigned long long A, B, C, result;
unsigned long long fuc(unsigned long long);
int main() {
	cin >> A>> B>> C;
	cout << fuc(B) % C;
}

unsigned long long fuc(unsigned long long n) {
	if (n == 0) {
		return 1;
	}
	else if(n == 1){
		return A % C;
	}
	else if (n % 2 == 0) {
		return (fuc(n / 2)*fuc(n / 2)) % C;
	}
	else if (n % 2 == 1) {
		return (fuc(n - 1)) * A % C;
	}
}

