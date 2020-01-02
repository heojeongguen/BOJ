#include <iostream>

using namespace std;

int main() {
	int arr[5] = { 0, };
	int total = 0;
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		if (arr[i] < 40) {
			arr[i] = 40;
			total += 40;
		}
		else {
			total += arr[i];
		}
	}
	cout << total / 5 << endl;
}