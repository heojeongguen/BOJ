#include <iostream>

using namespace std;

int main() {
	int N, X, Y;
	int arr[4];
	int tmp;
	cin >> N;
	for (int i = 1; i <= 3; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < N; i++) {
		cin >> X;
		cin >> Y;
		tmp = arr[Y];
		arr[Y] = arr[X];
		arr[X] = tmp;
	}
	for (int i = 1; i <= 3; i++) {
		if (arr[i] == 1) {
			cout << i << endl;
		}
	}
}