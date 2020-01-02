#include <iostream>
#include <algorithm>
using namespace std;


int arr[3];

int main() {
	int N;
	int mmin = 100000001;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		mmin = min(arr[i], mmin);
	}
	for (int i = 1; i <= mmin; i++) {
		bool suc = true;
		for (int j = 0; j < N; j++) {
			if (arr[j] % i != 0) suc = false;
		}
		if (suc) cout << i << "\n";
	}
}