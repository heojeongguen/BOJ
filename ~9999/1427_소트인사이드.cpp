#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(char a, char b) {
	return (int)a - 48 > (int)b - 48;
}

int main() {
	string str;
	cin >> str;
	sort(str.begin(), str.end(), compare);
	for (const auto &x : str) {
		cout << x;
	}
	cout << endl;
}