#include <iostream>
#include <algorithm>
#define LEFT(i) (i*2)
#define RIGHT(i) (i*2+1)
#define MMAX 100000
#define NMAX 300
using namespace std;
typedef unsigned long long ll;
int arr[301][301];
int tree[3 * MMAX];
int ans[301][301];
int k;
void updateTree(int now, int num, int l, int r, bool ADD) {
	int mid = (l + r) / 2;
	if (num >= l && num <= r) {
		if (ADD) tree[now]++;
		else tree[now]--;
	}
	if (l == r) return;

	updateTree(LEFT(now), num, l, mid, ADD);
	updateTree(RIGHT(now), num, mid + 1, r, ADD);
}

void deleteTree(int deleteNum, int insertNum) {
	updateTree(1, deleteNum, 0, k, false);
	updateTree(1, insertNum, 0, k, true);
}

int getMedian(int now, int k, int l, int r) {
	int mid = (l + r) / 2;
	
	if (l == r) return l;

	if (tree[LEFT(now)] < k)
		getMedian(RIGHT(now), k - tree[LEFT(now)], mid + 1, r);
	else
		getMedian(LEFT(now), k, l, mid);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int r, c, w;
	int m;
	cin >> r >> c >> k >> w;
	m = ( ( (w * w) + 1) / 2);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w; j++) {
			updateTree(1, arr[i][j], 0, k, true);
		}
	}
	ans[0][0] = getMedian(1, m, 0, k);

	for (int i = 0; i <= r - w; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j <= c - w; j++) {
				if (j == 0)continue;
				for (int z = i; z < i + w; z++) {
					deleteTree(arr[z][j -1], arr[z][j + w - 1]);
				}
				ans[i][j] = getMedian(1, m, 0, k);

				if (j == c - w) {
					for (int z = j; z < j + w; z++) {
						deleteTree(arr[i][z], arr[i+w][z]);
					}
				}
				ans[i+1][j] = getMedian(1, m, 0, k);
			}
		}
		else {
			for (int j = c - w; j >= 0; j--) {
				if (j == c - w)continue;

				for (int z = i; z < i + w; z++) {
					deleteTree(arr[z][j + w], arr[z][j]);
				}
				ans[i][j] = getMedian(1, m, 0, k);

				if (j == 0) {
					for (int z = j; z < j + w; z++) {
						deleteTree(arr[i][z], arr[i + w][z]);
					}
				}
				ans[i + 1][j] = getMedian(1, m, 0, k);
			}
		}
	}
	for (int i = 0; i <= r - w; i++) {
		for (int j = 0; j <= c - w; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}