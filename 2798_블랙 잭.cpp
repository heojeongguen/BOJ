#include <iostream>
#include <algorithm>
using namespace std;
int arr[101];
int main() {
	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int mmax = 0;
	
	for (int i = 0; i < N-2; i++) {
		for (int j = i + 1; j < N-1; j++) {
			for (int z = j + 1; z < N; z++) {
				int tmp = arr[i] + arr[j] + arr[z];
				if (tmp <= Q) {
					mmax = max(mmax, tmp);
				}
			}
		}
	}
	cout << mmax << endl;
}