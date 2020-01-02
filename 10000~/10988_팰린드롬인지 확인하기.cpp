#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	bool suc = true;
	for (int i = 0, j = str.size() - 1; i < str.size(); i++, j--) {
		if (str[i] != str[j]) {
			suc = false;
		}
	}
	if (!suc) cout << "0" << endl;
	else cout << "1" << endl;
}