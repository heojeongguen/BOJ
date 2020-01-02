#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, T;
	cin >> N >> T;
	int curTime = 0;
	int processTime;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> processTime;
		curTime += processTime;
		if (curTime > T) break;
		cnt++;
	}
	cout << cnt << endl;
}
