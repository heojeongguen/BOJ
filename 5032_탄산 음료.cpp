#include <iostream>

using namespace std;

int main() {
	int e, f, c;
	cin >> e >> f >> c;
	int ans = 0;
	int cnt = e + f;

	while (true) {
		ans += cnt / c;
		cnt = (cnt / c) + (cnt % c);
		if (cnt < c) break;
	}
	cout << ans << endl;
}