#include <iostream>

using namespace std;

int main() {
	long ans = 0;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		ans += i;
	}
	cout << ans << endl;
}