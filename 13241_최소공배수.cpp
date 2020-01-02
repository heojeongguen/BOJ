#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	unsigned long long A, B, T;
	unsigned long long  heo = 1;
	unsigned long long  kim = 1;
	unsigned long long  mini;
	cin >> A >> B;
	mini = min(A, B);
	for (int i = mini; i >= 1; i--) {
		if (A % i == 0 && B % i == 0) {
			heo = i;
			break;
		}
	}
	kim = A * B / heo;
	cout << kim << endl;
}