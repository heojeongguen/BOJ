#include <iostream>
#include <string>
using namespace std;

int arr[2001][2001];
int R = 1000;
int C = 1000;
int cnt = 1;

int main() {
	arr[R][C] = 1;
	int n;
	cin >> n;
	string str;
	cin >> str;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'N') {
			R++;
			if (arr[R][C] == 0) {
				cnt++;
				arr[R][C] = 1;
			}
		}
		else if (str[i] == 'E') {
			C++;
			if (arr[R][C] == 0) {
				cnt++;
				arr[R][C] = 1;
			}
		}
		else if (str[i] == 'S') {
			R--;
			if (arr[R][C] == 0) {
				cnt++;
				arr[R][C] = 1;
			}
		}
		else if (str[i] == 'W') {
			C--;
			if (arr[R][C] == 0) {
				cnt++;
				arr[R][C] = 1;
			}
		}
	}
	cout << cnt << "\n";
}