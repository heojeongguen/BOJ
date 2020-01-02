#include <iostream>
#include <vector>
#include <algorithm>

int arr[10001];

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int data;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> data;
		arr[data]++;
	}

	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << i << "\n";
		}
	}
}