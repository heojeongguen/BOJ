#include<iostream>
#include <vector>
#include <algorithm>
// 그냥 앞에서부터 쭊쭊나가면됨
using namespace std;
int arr[1000][3];
int done[1000];
int N;


int main() {
	int data, ans = 0;
	int result[3] = { 0, };
	char last, MIN;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> data;
			arr[i][j] = data;
		}
		if (i == 0) {
			result[0] = arr[0][0];
			result[1] = arr[0][1];
			result[2] = arr[0][2];
		}
		else {
			int prevR = result[0];
			int prevG = result[1];
			int prevB = result[2];
			result[0] = min(prevG + arr[i][0], prevB + arr[i][0]);
			result[1] = min(prevR + arr[i][1], prevB + arr[i][1]);
			result[2] = min(prevR + arr[i][2], prevG + arr[i][2]);
		}
	}
	cout << min({ result[0],result[1],result[2] });
}