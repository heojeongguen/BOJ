#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string a, b, c, d; cin >> a >> b >> c >> d;
	a.append(b);
	c.append(d);
	ll A = stoll(a);
	ll C = stoll(c);
	cout << A + C << endl;
}