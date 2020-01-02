#include <iostream>

using namespace std;

int N;

int arr[1000000];


int main() {
	cin >> N;
	arr[1] = 3;
	arr[2] = 7;
	for (int i = 3; i <= N; i++) {
		arr[i] = (2 * arr[i - 1] + arr[i - 2]) % 9901;
	}
	cout << arr[N];
}