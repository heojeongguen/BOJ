#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int arr[1001][1001];
int main() {
	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 0; i < str2.size(); i++) {
		for (int j = 0; j < str1.size(); j++) {
			if (str2.at(i) == str1.at(j)) {
				arr[i+1][j+1] = arr[i][j] + 1;
			}
			else {
				arr[i + 1][j + 1] = max(arr[i + 1][j], arr[i][j + 1]);
			}
		}
	}
	cout << arr[str2.size()][str1.size()] << endl;

}
/* 바텀업 ! ( flag로인해 메모리초과 ! 가장 최적방법보다 메모리 약 250 배필요)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool dp[1000][1000][1000];
string str1;
string str2;
int index = 0;
int ans = 0;

void fuc(int const &up, int const &down, int const &count) {
	if (dp[up][down][count] == true) {
		return;
	}
	else {
		dp[up][down][count] = true;
		if (up == str1.size() || down == str2.size()) {
			ans = max(ans, count);
			return;
		}
		else {
			for (int i = down; i < str2.size(); i++) {
				if (str1.at(up)== str2.at(i)) {
					fuc(up + 1, i + 1, count + 1);
					break;
				}
			}
		}
		fuc(up + 1, down, count);
	}	
}
int main() {
	cin >> str1 >> str2;
	fuc(0, 0, 0);
	cout << ans << endl;
}*/