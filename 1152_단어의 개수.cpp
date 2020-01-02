#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int ans=0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getline(cin, str);
	bool start = false;
	for (int i = 0; i < str.size(); i++) {
		if (str.at(i) == ' ') {
			if (start) {
				ans++;
				start = false;
			}
		}
		else {
			if (!start) start = true;
		}
	}
	if (start) {
		ans++;
	}
	cout << ans << endl;
}