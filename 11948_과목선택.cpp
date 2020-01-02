#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int sum = 0;
	vector<int> a;
	vector<int> b;
	for (int i = 0; i < 4; i++) {
		int data; cin >> data;
		a.push_back(data);
	}
	for (int i = 0; i < 2; i++) {
		int data; cin >> data;
		b.push_back(data);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 3; i >= 1; i--) {
		sum += a[i];
	}
	sum += b[1];
	cout << sum << endl;
}