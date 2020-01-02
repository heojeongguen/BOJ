#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------

double getDist(int x1, int y1, int x2, int y2) {
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int n; cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int x, y, r; cin >> x >> y >> r;
			double dist1 = getDist(x, y, x1, y1);
			double dist2 = getDist(x, y, x2, y2);
			if (dist1 < r && dist2 > r) ans++;
			if (dist1 > r && dist2 < r) ans++;
		}
		cout << ans << endl;
	}
}