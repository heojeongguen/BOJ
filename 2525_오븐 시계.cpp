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
	int A, B, C; cin >> A >> B >> C;
	int sec = A * 3600 + B * 60 + C * 60;
	sec %= (3600 * 24);
	int AA = sec / 3600; sec %= 3600;
	int BB = sec / 60; sec %= 60;
	cout << AA << " " << BB << endl;

}