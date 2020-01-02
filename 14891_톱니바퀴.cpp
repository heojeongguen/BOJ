#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[4][8];
bool cycle[4];
void LL(int);
void RR(int);
void RR(int now) {
	if (cycle[now] == true) return;
	cycle[now] = true;

	if (now == 0) {
		if (arr[now][2] != arr[now + 1][6]) {
			LL(now + 1);
		}
	}else if (now == 3) {
		if (arr[now][6] != arr[now - 1][2]) {
			LL(now - 1);
		}
	}
	else {
		if (arr[now][2] != arr[now + 1][6]) {
			LL(now + 1);
		}
		if (arr[now][6] != arr[now - 1][2]) {
			LL(now - 1);
		}
	}

	int tmp = arr[now][7];
	for (int i = 7; i > 0; i--) {
		arr[now][i] = arr[now][i - 1];
	}
	arr[now][0] = tmp;
}
void LL(int now) {

	if (cycle[now] == true) return;
	cycle[now] = true;

	if (now == 0) {
		if (arr[now][2] != arr[now + 1][6]) {
			RR(now + 1);
		}
	}
	else if (now == 3) {
		if (arr[now][6] != arr[now - 1][2]) {
			RR(now - 1);
		}
	}
	else {
		if (arr[now][2] != arr[now + 1][6]) {
			RR(now + 1);
		}
		if (arr[now][6] != arr[now - 1][2]) {
			RR(now - 1);
		}
	}

	int tmp = arr[now][0];
	for (int i = 0; i <= 6; i++) {
		arr[now][i] = arr[now][i+1];
	}
	arr[now][7] = tmp;
}

int main() {
	string str;
	for (int i = 0; i < 4; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j] - '0';
		}
	}
	int N;
	cin >> N;
	int n, direc;
	for (int i = 0; i < N; i++) {
		cin >> n >> direc;
		for (int j = 0; j <= 3; j++) {
			cycle[j] = false;
		}
		if (direc == 1) {
			RR(n-1);
		}
		else {
			LL(n-1);
		}
	}

	int point = 1;
	int ans = 0;

	
	for (int i = 0; i < 4; i++) {
		if (arr[i][0] == 1) ans += point;
		point *= 2;
	}
	cout << ans << endl;
}