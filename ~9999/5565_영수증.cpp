#include <iostream>

using namespace std;

int main() {
	int total, data;
	cin >> total;
	for (int i = 0; i < 9; i++) {
		cin >> data;
		total -= data;
	}
	cout << total << endl;
}