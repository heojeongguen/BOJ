#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		cout << "String #" << i + 1<< endl;
		for (int i = 0; i < str.size(); i++) {
			if ((int)str[i] == 'Z') cout << 'A';
			else {
				cout << (char)((int)str[i] + 1);
			}
		}
		cout << "\n\n";
	}
}