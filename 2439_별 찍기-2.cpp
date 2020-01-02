#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

int main() {
	int N;
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		str = "";
		cout.width(N);
		for (int j = 0; j < i + 1; j++) {
			str += "*";
		}
		cout << str << endl;
	}
}