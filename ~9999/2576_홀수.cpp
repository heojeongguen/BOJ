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
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int sum = 0;
	int mmin = 101;
	for (int i = 0; i < 7; i++) {
		int data; cin >> data;
		if (data % 2 == 1) {
			mmin = min(mmin, data);
			sum += data;
		}
	
	}
	if (mmin == 101) cout << -1 << endl;
	else cout << sum << "\n" << mmin << endl;
}