#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
bool dp[101][101][101];
int arr[101][101][101];
vector<tuple<int, int, int>> tomato;

int ans = 0;

int main() {
	int total;
	int col, row , hei;
	int cnt = 0;

	cin >> col >> row >> hei;
	total = col * row * hei;
	for (int h = 0; h < hei; h++) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> arr[h][i][j];
				if (arr[h][i][j] == 1) {
					tomato.push_back(make_tuple(h,i, j));
					dp[h][i][j] = true;
					cnt++;
				}
				else if (arr[h][i][j] == -1) total--;
			}
		}
	}
	while (!tomato.empty()) {
		vector<tuple<int,int, int>> tmp;
		for (int i = 0; i < tomato.size(); i++) {
			int H = get<0>(tomato.at(i));
			int R = get<1>(tomato.at(i));
			int C = get<2>(tomato.at(i));
			if (R - 1 >= 0 && dp[H][R - 1][C] == false && arr[H][R - 1][C] != -1) {
				dp[H][R - 1][C] = true;
				arr[H][R - 1][C] = 1;
				tmp.push_back(make_tuple(H,R - 1, C));
				cnt++;
			}
			if (R + 1 < row && dp[H][R + 1][C] == false && arr[H][R + 1][C] != -1) {
				dp[H][R + 1][C] = true;
				arr[H][R + 1][C] = 1;
				tmp.push_back(make_tuple(H, R + 1, C));
				cnt++;
			}
			if (C - 1 >= 0 && dp[H][R][C - 1] == false && arr[H][R][C - 1] != -1) {
				dp[H][R][C - 1] = true;
				arr[H][R][C - 1] = 1;
				tmp.push_back(make_tuple(H, R, C - 1));
				cnt++;
			}
			if (C + 1 < col && dp[H][R][C+1] == false && arr[H][R][C + 1] != -1) {
				dp[H][R][C + 1] = true;
				arr[H][R][C + 1] = 1;
				tmp.push_back(make_tuple(H, R, C+1));
				cnt++;
			}
			if (H - 1 >= 0 && dp[H - 1][R][C] == false && arr[H - 1][R][C] != -1) {
				dp[H - 1][R][C] = true;
				arr[H - 1][R][C] = 1;
				tmp.push_back(make_tuple(H-1, R, C));
				cnt++;
			}
			if (H +1 < hei && dp[H+1][R][C] == false && arr[H + 1][R][C] != -1) {
				dp[H + 1][R][C] = true;
				arr[H + 1][R][C] = 1;
				tmp.push_back(make_tuple(H + 1, R , C));
				cnt++;
			}
		}
		ans++;
		tomato = tmp;
	}
	if (total == cnt) {
		cout << ans - 1 << endl;
	}
	else {
		cout << -1 << endl;
	}
}