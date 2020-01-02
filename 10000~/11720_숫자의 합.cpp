#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, result;
	cin >> N;
	string str = "";
	cin >> str;
	result = 0;
	for (int i = 0; i < N; i++) {
		result += (int)str.at(i) - 48;
	}
	cout << result;
}