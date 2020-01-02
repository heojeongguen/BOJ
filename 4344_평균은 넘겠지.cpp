#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	int C1, C2;
	double d, total, m, count;
	vector<double> p;
	vector<double> s;
	cin >> C1;
	for (int i = 0; i < C1; i++) {
		total = 0;
		m = 0;
		cin >> C2;
		count = 0;
		s.clear();
		for (int j = 0; j < C2; j++) {
			cin >> d;
			s.push_back(d);
		}
		for (const auto &x : s) {
			total += x;
		}
		m = total / C2;
		for (const auto &x : s) {
			if (x > m) {
				count++;
			}
		}
		p.push_back((count / C2) * 100);
	}
	cout.precision(3);
	for (const auto &x : p) {
		cout << fixed << x << "%" << endl;
	}
}