#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str;
	char a;
	vector<char> vec;
	while (true) {
		vec.clear();
		getline(cin, str);
		if (str == "END") {
			break;
		}
		for (int i = 0; i < str.size(); i++) {
			vec.push_back(str.at(0));
		}
		reverse(str.begin(),str.end());
		cout << str << endl;
	}
}