#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> vec;
int main() {
	int D;
	char D2;
	for (int i = 0; i < 3; i++) {
		cin >> D;
		vec.push_back(D);
	}
	sort(vec.begin(), vec.end());
	
	for (int i = 0; i < 3; i++) {
		cin >> D2;
		cout << vec.at(D2 - 65) << " ";
	}

}