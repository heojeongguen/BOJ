#include <iostream>
#include <algorithm>
using namespace std;

int T, n;
bool open[101];
bool escape[101];
int main() {
	cin >> T;
	while (T--) {
		fill(open, open + 101, false);
		fill(escape, escape + 101, false);
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; i * j <= n; j++) {
				if (!open[j * i]) {
					open[j * i] = true;
					ans++;
				}
				else {
					open[j * i] = false;
					ans--;
				}
			}
		}
		cout << ans << endl;
	}
}