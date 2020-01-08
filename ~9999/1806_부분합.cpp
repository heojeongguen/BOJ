#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define endl '\n'
typedef long long ll;

int arr[100001];
ll sum[100001];


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, S, ret; cin >> N >> S;
	ret = 1e9;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] >= S) ret = 1;
	}
	if (ret == 1e9) {
		int l = 0, r = 0, sum = arr[0];
		while (r < N && l <= r) {
			if (sum < S) {
				sum += arr[++r];
			}
			if (sum >= S) {	
				ret = min(ret, r - l + 1);
				sum -= arr[l];
				l++;
			}
		}
	}
	if (ret == 1e9) cout << 0 << endl;
	else cout << ret << endl;
}