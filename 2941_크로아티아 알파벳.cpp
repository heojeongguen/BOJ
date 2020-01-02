#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string arr[8] = { "c=", "c-","dz=","d-","lj","nj","s=","z=" };
	string str;
	cin >> str;
	size_t pos;
	int count = 0;
	bool go = true;
	while (go) {
		go = false;
		int size = 0;
		for (int i = 0; i < 8; i++) {
			if ((pos = str.find(arr[i], 0)) != std::string::npos) {
				str.replace(str.begin() + pos, str.begin() + pos + arr[i].size(), "*");
				count++;
				go = true;
				break;
			}
		}
	}
	for (const auto & x : str) {
		if (x != '*') {
			count++;
		}
	}
	cout << count;
}