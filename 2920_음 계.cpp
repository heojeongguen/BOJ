#include <iostream>
#include <string>

using namespace std;
int main() {
	int arr[8];
	string ans;
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}
	if (arr[0] == 1) {
		ans = "ascending";
		for (int i = 1; i < 8; i++) {
			if (arr[i] != i + 1) {
				ans = "mixed";
			}
		}
	}else if (arr[0] == 8) {
		ans = "descending";
		for (int i = 1; i < 8; i++) {
			if (arr[i] != 8 - i) {
				ans = "mixed";
			}
		}
	}
	cout << ans << endl;
}