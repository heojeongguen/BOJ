#include <iostream>

using namespace std;

int main() {
	int T, W, H, N, w, h;
	cin >> T;
	while (T--) {
		cin >> H >> W >> N;
		w = 1;
		h = 0;
		while (N--) {
			h++;
			if (h > H) {
				w++;
				h = 1;
			}
		}
		cout << h;
		if (w < 10) {
			cout << "0" << w << endl;
		}
		else {
			cout << w << endl;
		}
	}
}