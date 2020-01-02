#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int N,c;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> c;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			for (int j = 0; j < c; j++) {
				cout << str.at(i);
			}
		}
		cout << endl;
	}
}