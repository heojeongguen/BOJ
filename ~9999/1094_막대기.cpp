#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	int M = 64;
	int total = 64;
	int ans = 1;
	while (true) {
		if (total == N) {
			break;
		}
		if (N < total) {
			M /= 2;
			if (total - M >= N) {
				total -= M;
			}
			else {
				ans++;
			}
		}
	}
	cout << ans << endl;
}