#include <iostream>
#include <vector>
using namespace std;
int main() {
	int arr[1001];
	int N;
	int data, count = 0;
	vector<int> vec;
	cin >> N;
	bool can;
	for (int i = 0; i < N; i++) {
		cin >> data;
		can = true;
		if (data != 1) {
			for (int i = 2; i < data; i++) {
				if (data % i == 0) {
					can = false;
					break;
				}
			}
			if (can)
				count++;
		}
	}
	cout << count;
}