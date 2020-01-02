#include <iostream>
#include <string>
using namespace std;

int arr[26];

int main() {
	int N;
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		arr[(int)str[0] - 97]++;
	}
	bool one = false;
	for (int i = 0; i < 26; i++) {
		if (arr[i] >= 5) {
			one = true;
			cout << (char)(i + 97);
		}
	}
	if (!one) cout << "PREDAJA" << endl;
}