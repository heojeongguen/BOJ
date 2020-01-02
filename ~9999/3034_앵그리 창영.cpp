#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double n, w, h;
	double d;
	cin >> n >> w >> h;
	double len = sqrt((w * w) + (h * h));
	for (int i = 0; i < n; i++) {
		cin >> d;
		if (len < d) cout << "NE\n";
		else cout << "DA\n";
	}
}