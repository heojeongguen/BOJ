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
	ll sum = 0;
	for (int i = 0; i < 5; i++) {
		ll data; cin >> data;
		sum += data * data;
	}
	cout << sum % 10 << endl;
}