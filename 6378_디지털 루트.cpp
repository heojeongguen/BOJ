#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	while (true) {
		cin >> str;
		if (str.size() == 1 && str[0] == '0') break;
		while (true) {
			int tmp = 0;
			for (int i = 0; i < str.size(); i++) {
				tmp += (int)str[i] - 48;
			}
			str = to_string(tmp);
			if (str.size() == 1) break;
		}
		cout << str[0] << endl;
	}
}