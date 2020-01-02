#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1001][1001];
bool arr2[1001];

int main() {
	string origin, result;
	int lcs;
	int ans = 0;
	bool flag = false;
	cin >> origin >> result;

	for (int i = 0; i <= origin.size(); i++) {
		arr[0][i] = i;
	}
	for (int i = 0; i <= result.size(); i++) {
		arr[i][0] = i;
	}
	int min_size = min(result.size(), origin.size());
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < origin.size(); j++) {
			if (origin.at(j) == result.at(i)) {
				arr[i + 1][j + 1] = arr[i][j];
			}
			else {
				arr[i + 1][j + 1] = min({ arr[i][j] + 1,arr[i + 1][j] + 1, arr[i][j + 1] + 1 });
			}
		}
	}
	//cout << "0 0 ";
	//for (const auto &x : origin) {
	//	cout << x << " ";
	//}
	//cout << endl;
	//for (int i = 0; i <= result.size(); i++) {
	//	if (i == 0) {
	//		cout << "0 ";
	//	}
	//	if (i > 0) {
	//		cout << result.at(i - 1) << " ";
	//	}
	//	for (int j = 0; j <= origin.size(); j++) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	cout << arr[result.size()][origin.size()] << endl;
}