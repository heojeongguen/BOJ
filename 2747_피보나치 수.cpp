#include <iostream>

using namespace std;
unsigned long long arr[45];

int main() {
	int N;
	cin >> N;
	arr[0] = 1;
	arr[1] = 1;
	if (N <= 2) {
		cout << arr[N-1];
	}
	else {
		for (int i = 2; i <= N; i++) {
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		cout << arr[N-1] << endl;
	}

	
}