#include <iostream>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N; char tag;
		char c;
		int a;
		cin >> N >> tag;
		if (tag == 'C') {
			for (int i = 0; i < N; i++) {
				cin >> c;
				cout << (int)c - 64 << " ";
			}
			cout << endl;
		}else if(tag == 'N'){
			for (int i = 0; i < N; i++) {
				cin >> a;
				cout << (char)(a + 64) << " ";
			}
			cout << endl;
		}
	}
}