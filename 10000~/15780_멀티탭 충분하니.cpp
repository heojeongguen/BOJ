#include <iostream>
#include <vector>
using namespace std;

vector<int> multi;

int main() {
	int N, Q,D;
	int cnt = 0;
	cin >> N >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> D;
		if (D % 2 == 0)cnt += (D / 2);
		else cnt += (D / 2) + 1;
	}
	if (cnt >= N) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}