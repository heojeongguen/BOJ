#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[41][41];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int R, C,T;
	int D, cnt = 0;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> T;
	vector<int> vec;
	for (int i = 0; i <= R - 3; i++) {
		for (int j = 0; j <= C - 3; j++) {
			vec.clear();
			for (int x = i; x < i + 3; x++) {
				for (int y = j; y < j + 3; y++) {
					//cout << i << " " << j << " " << x << " " << y << endl;
					vec.push_back(arr[x][y]);
				}
			}
		
			sort(vec.begin(), vec.end());
			//cout << "[" << i << "][" << j << "] : " << vec[vec.size() / 2] << endl;
			if (T <= vec[vec.size() / 2] ) cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}