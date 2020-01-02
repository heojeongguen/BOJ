#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<char> vec;
	bool wait = true;
	string str;
	cin >> str;
	for (const auto & x : str) {
		if (wait == true) {
			vec.push_back(x);
			wait = false;
		}
		if ((int)x == 45) {
			wait = true;
			
		}
	}
	
	for (const auto & x : vec) {
		cout << x;
	}
}