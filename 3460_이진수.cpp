#include <iostream>

using namespace std;

int main() {
	int T, N;
	cin >> T;
	while (T--) {
		
		cin >> N;
		int cnt = 0;
		while (N > 0) {
			if (N % 2 == 1) cout << cnt << " ";
			N /= 2;
			cnt++;
		}
		cout << endl;
	}

}