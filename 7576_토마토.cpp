#include <iostream>
#include <vector>
using namespace std;
bool dp[1001][1001];
int arr[1001][1001];
vector<pair<int, int>> tomato;

int ans = 0;

int main() {
	int total;
	int col, row;
	int cnt = 0;

	cin >> col >> row;
	total = col * row;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				tomato.push_back(make_pair(i, j));
				dp[i][j] = true;
				cnt++;
			}
			else if (arr[i][j] == -1) total--;
		}
	}
	while (!tomato.empty()) {
		vector<pair<int, int>> tmp;
		for (int i = 0; i < tomato.size(); i++) {
			int R = tomato.at(i).first;
			int C = tomato.at(i).second;
			if (R - 1 >= 0 && dp[R - 1][C] == false && arr[R - 1][C] != -1) {
				dp[R - 1][C] = true;
				arr[R - 1][C] = 1;
				tmp.push_back(make_pair(R - 1, C));
				cnt++;
			}
			if (R + 1 < row  && dp[R + 1][C] == false && arr[R + 1][C] != -1) {
				dp[R + 1][C] = true;
				arr[R + 1][C] = 1;
				tmp.push_back(make_pair(R + 1, C));
				cnt++;
			}
			if (C - 1 >= 0 && dp[R][C - 1] == false && arr[R][C - 1] != -1) {
				dp[R][C - 1] = true;
				arr[R][C - 1] = 1;
				tmp.push_back(make_pair(R, C - 1));
				cnt++;
			}
			if (C + 1 < col && dp[R][C + 1] == false && arr[R][C + 1] != -1) {
				dp[R][C + 1] = true;
				arr[R][C + 1] = 1;
				tmp.push_back(make_pair(R, C + 1));
				cnt++;
			}
		}
		//for (int a = 0; a < row; a++) {
		//	for (int b = 0; b < col; b++) {
		//		cout << arr[a][b] << " ";
		//	}
		//	cout << endl;
		//}
		ans++;
		tomato = tmp;
	}
	if (total == cnt) {
		//cout << " total : " << total << " cn t : " << cnt << endl;
		cout << ans - 1<< endl;
	}
	else {
		cout << -1 << endl;
	}
}