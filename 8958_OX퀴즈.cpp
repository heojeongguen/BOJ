#include <iostream>
#include <string>

using namespace std;
int main() { 
	int T, count, total;
	string str;
	cin >> T;
	while (T--) {
		total = 0;
		count = 0;
		cin >> str;
		for (const auto &x : str) {
			if (x == 'O') {
				total += count + 1;
				count++;
			}
			else {
				count = 0;
			}
		}
		cout << total << endl;
	}
}