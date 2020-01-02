#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	int row, col;
	string a, b;
	cin >> a >> b;
	bool find = false;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) {
				row = j;
				col = i;
				find = true;
				break;
			}
		}
		if (find) break;
	}
	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			if (col == j) cout << b[i];
			else if (row == i) cout << a[j];
			else cout << ".";
		}
		cout << endl;
	}
}