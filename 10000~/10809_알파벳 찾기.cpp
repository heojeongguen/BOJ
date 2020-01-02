#include <iostream>
#include <string>
using namespace std;


int main() {
	string str;
	getline(cin, str);
	int arr[26];

	for (int i = 0; i < 26; i++) {
		arr[i] = -1;
	}

	for (int i = 0; i < str.size(); i++) {
		if (arr[(int)str.at(i) - 97] == -1) {
			arr[(int)str.at(i) - 97] = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}

}