#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, data;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		vec.clear();
		int dp[10001] = { 0, };
		cin >> data;
		for (int i = 2; i < data; i++) {
			if (dp[i] == 0) {
				dp[i] = 1;
				vec.push_back(i);
			}
			for (int j = 1; j * i < data; j++) {
				dp[i * j] = 1;
			}
		}
		bool find = false;
		int index;
		if (vec.size() % 2 == 0) {
			index  = vec.size() / 2 - 1;
		}
		else {
			index = vec.size() / 2;
		}
		for (int i = index; i < vec.size(); i++) {
			for (int j = i; j >= 0; j--) {
				if (vec.at(i) + vec.at(j) == data) {
					cout << vec.at(j) << " " << vec.at(i) << "\n";
					find = true;
					break;
				}
			}
			if (find) {
				break;
			}
		}
	}
}