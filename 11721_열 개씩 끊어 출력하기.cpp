#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (i != 0 && i % 10 == 0) {
			cout << endl;
		}
		cout << str.at(i);
	}
}