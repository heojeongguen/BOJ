#include <iostream>

using namespace std;

int main() {
	int total = 0, mini = -1;
	int M, N;
	cin >> M >> N;
	for (int i = 1; i * i <= 10000; i++) {
		if (i * i> N) break;

		if (i * i >= M) {
			if (mini == -1) mini = i * i;
			total += i * i;
		}
	}
	if (mini == -1) {
		cout << mini << endl;
	}
	else {
		cout << total << endl << mini;
	}
	
}
