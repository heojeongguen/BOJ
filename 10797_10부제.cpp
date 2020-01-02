#include <iostream>
using namespace std;
int main() {
	int n, car, ans = 0;;
	cin >> n;
	for (int i = 0; i < 5; i++) {
		cin >> car;
		if (n == car) ans++;
	}
	cout << ans << endl;
}