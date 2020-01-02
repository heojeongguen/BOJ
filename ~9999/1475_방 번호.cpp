#include <iostream>
#include <string>
#include <vector>
using namespace std;
int arr[10];
int ans = 0;
void preSet() {
	ans++;
	for (int i = 0; i < 10; i++) {
		if (i == 9) {
			arr[6] = 2;
		}
		arr[i] = 1;
	}
}

int main() {
	string str;

	cin >> str;
	int index, size;
	size = str.size();
	int  count = 0;

	while (count != size) {
		preSet();
		for (int i = 0; i < str.size(); i++) {
			if (str.at(i) != '*') {
				if ((int)str.at(i) - 48 == 9 || (int)str.at(i) - 48 == 6) {
					index = 6;
				}
				else {
					index = (int)str.at(i) - 48;
				}
				if (arr[index] > 0) {
					count++;
					str.at(i) = '*';
					arr[index]--;
				}
			}
		}
	}
	cout << ans;
}