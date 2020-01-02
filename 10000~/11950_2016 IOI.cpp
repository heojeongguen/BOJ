#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------
int arr[51][3];



int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int R, C; cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char c; cin >> c;
			int index;
			if (c == 'W') index = 0;
			else if (c == 'B') index = 1;
			else index = 2;
			arr[i][index]++;
		}
	}
	int ans = 1e9;
	// 1 ~ R-2 중에 모든 구간을 다 선택할수있따
	for (int i = 0; i < R; i++) {
		for (int size = 1; size < R - i; size++) {
			int tmp = 0;
			bool a = false, b = false, c = false;
			for (int j = 0; j < i; j++) {
				tmp += arr[j][1] + arr[j][2];
				a = true;
			}
			for (int j = i; j < i + size; j++) {
				tmp += arr[j][0] + arr[j][2];
				b = true;
			}
			for (int j = i + size; j < R; j++) {
				tmp += arr[j][0] + arr[j][1];
				c = true;
			}
			if(a && b && c)
				ans = min(ans, tmp);
		}
	}
	cout << ans << endl;
}