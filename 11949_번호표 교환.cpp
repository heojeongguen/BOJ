#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------

int arr[101];
int ans[101];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i + 1];
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 2; j <= N; j++) {
			int prev = (arr[j - 1]) % i;
			int now = (arr[j]) % i;
			if (prev > now) {
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << endl;
	}
}