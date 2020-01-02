#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll A, AA;
	ll B, BB;
	cin >> A >> AA;
	cin >> B >> BB;
	ll C = A * BB + AA * B;
	ll CC = AA * BB;
	ll mmax = max(C, CC);
	for (ll i = 2; i * i <= mmax; i++ ) {
		while (C % i == 0 && CC % i == 0) {
			C /= i;
			CC /= i;
		}
	}
	cout << C << " " << CC << endl;
}