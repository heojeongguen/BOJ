#include <iostream>

using namespace std;

unsigned long long arr[1000000];

int main() {
	unsigned long long N, M, data;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> data;
		arr[i] = data;
	}
	unsigned long long Max = 1000000000;
	unsigned long long Min = 0;
	unsigned long long middle = 0;
	unsigned long long sum;

	while (Min + 1 < Max) {
		sum = 0;
		middle = (Max + Min) / 2;
		for (int i = 0; i < N; i++) {
			if (arr[i] > middle) {
				sum += arr[i] - middle;
			}
		}

		if (sum >= M) {
			Min = middle;
		}
		else {
			Max = middle;
		}
	}
	cout << Min << endl;
}