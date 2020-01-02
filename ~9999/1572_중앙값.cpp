#include <iostream>
#define LEFT(i) (i*2)
#define RIGHT(i) (i*2+1)
#define MMAX 65536
#define NMAX 250001
using namespace std;
typedef unsigned long long ll;

int tree[3 * NMAX];
int arr[NMAX];

void updateTree(int now, int num, int l, int r, bool ADD) {
	int mid = (l + r) / 2;
	if (num <= r && num >= l) {
		if (ADD)tree[now]++;
		else tree[now]--;
	}
	else {
		return;
	}

	if (l == r) return;
	updateTree(LEFT(now), num, l, mid, ADD);
	updateTree(RIGHT(now), num, mid+1, r, ADD);
}

void updateTree(int deleteNum, int insertNum) {
	updateTree(1, deleteNum, 0, MMAX, false);
	updateTree(1, insertNum, 0, MMAX, true);
}

ll getMedain(int now, int k, int l, int r) {
	int mid = (l + r) / 2;

	if (l == r) return l;

	if (tree[LEFT(now)] < k)
		getMedain(RIGHT(now), k - tree[LEFT(now)], mid + 1, r);
	else
		getMedain(LEFT(now), k, l, mid);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll ans = 0;
	int n, k;
	cin >> n >> k;
	int m = (k + 1) / 2;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < k; i++) {
		updateTree(1, arr[i], 0, MMAX, true);
	}
	ans += getMedain(1, m, 0, MMAX);
	for (int i = 0; i < n - k; i++) {
		updateTree(arr[i], arr[i + k]);
		ans += getMedain(1, m, 0, MMAX);
	}
	cout << ans << "\n";
}