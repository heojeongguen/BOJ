#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int A, B; cin >> A >> B;
	cout << A * (B-1) + 1 << endl;
}