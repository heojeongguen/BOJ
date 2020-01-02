#include <iostream>

using namespace std;



int main() {

	int data, count;

	while (true) {
		int dp[246913] = { 0, };
		int count = 0;
		cin >> data;
		if (data == 0) {
			break;
		}
		for (int i = 2; i <= data * 2; i++) {
			if (dp[i] == 0 && i > data) {
				count++;
			}
			for (int j = 1; j * i <= data * 2; j++) {
				dp[i * j] = 1;
			}
		}
		cout << count << endl;
	}

}