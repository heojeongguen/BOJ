#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int cnt = 9;
	int size = 1;
	int ans = 0;
	while (N > cnt) {
		N -= (cnt);
		ans += cnt * size;
		int tmp = cnt;
		cnt = (cnt * 10);
		size++;
	}
	ans += N * size;
	cout <<  ans << endl;
}