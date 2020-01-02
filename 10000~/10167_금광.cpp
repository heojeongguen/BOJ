#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int > pii;
#define INF (int)1e9 + 1
class Info {
public:
	int x, y, w;
	Info() {}
	Info(int x, int y, int w) { this->x = x; this->y = y; this->w = w; }
	bool operator < (const Info & b) const { return this->x < b.x; }
};
vector<Info> vec;
ll dp[3001][2];	int N;

ll fun(int n, ll s1, ll s2) {
	if (n >= N) return 0;

	if (dp[n][0] != -1 && dp[n][1] != -1) return max(dp[n][0], dp[n][1]);
	
	if (s1 == INF && s2 == INF) {
		dp[n][0] = max(dp[n][0], fun(n + 1, s1, s2));
		s1 = vec[n].y;
		dp[n][1] = max(dp[n][1], vec[n].w + fun(n + 1, s1,s2));
	}
	else if (s1 != INF || s2 == INF) {

	}
	else {

	}


	if (minY <= vec[n].y && maxY >= vec[n].y) {
		cout << n << "ÀÏ‹š case 1" << endl;
		dp[n][1] = max(dp[n][1], vec[n].w + fun(n + 1, min((ll)vec[n].y, minY), max((ll)vec[n].y, maxY)));
	}
	else {
		cout << n << "ÀÏ‹š case 2" << endl;
		dp[n][0] = max(dp[n][0], fun(n + 1, minY, maxY));
		dp[n][1] = max(dp[n][1], vec[n].w + fun(n + 1, min((ll)vec[n].y, minY), max((ll)vec[n].y, maxY)));
	}
	
	return max(dp[n][0],dp[n][1]);

}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		dp[i][0] = -1;
		dp[i][1] = -1;
	}

	for (int i = 0; i < N; i++) {
		int x, y, w; cin >> x >> y >> w;
		vec.push_back(Info(x, y, w));
	}

	sort(vec.begin(), vec.end());
	cout << fun(0, -INF, INF) << "\n";
}