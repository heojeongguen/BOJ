#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool arr[101][101];
pair<int, int> direc[4] = { {0,1},{-1,0},{0,-1},{1,0} };

void fuc(int nowX, int nowY, int d, int g) {
	vector <int> vec;
	arr[nowX][nowY] = true;
	nowX += direc[d].first;
	nowY += direc[d].second;
	arr[nowX][nowY] = true;
	vec.push_back(d);

	bool flag = true;
	for(int st = 0 ; st < g ; st++){
		int size = vec.size() - 1;
		for (int i = size; i >= 0; i--) {
			nowX += direc[(vec[i] + 1) % 4].first;
			nowY += direc[(vec[i] + 1) % 4].second;
			if (nowX < 0 || nowX > 100 || nowY < 0 || nowY > 100) {
				flag = false;
				break;
			}
			vec.push_back( (vec[i] + 1 ) % 4);
			arr[nowX][nowY] = true;
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	int x, y, d, g;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		fuc(y, x, d, g);
	}
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == true && arr[i + 1][j] == true && arr[i][j + 1] == true && arr[i + 1][j + 1] == true) {
				ans++;
			}
		}
	}
	cout << ans << "\n";
}