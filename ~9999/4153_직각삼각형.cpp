#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<unsigned long long> vec;
int main() {
	unsigned long long a, b, c;
	unsigned long long s, m, l;
	while (true) {
		cin >> a >> b >> c;
		if (a == 0) break;
		vec.clear();
		vec.push_back(a);
		vec.push_back(b);
		vec.push_back(c);
		sort(vec.begin(), vec.end());
		s = vec[0];
		m = vec[1];
		l = vec[2];
		if ((s * s) + (m*m) == (l*l)) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}
}