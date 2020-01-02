#include <iostream>
using namespace std;
#include <string>

#include <vector>
int main() {
	int cir = 0;
	int rec = 0;
	string str;
	cin >> str;
	vector<int> st;
	int tmp;
	bool fail = false;
	for (const auto &x : str) {

		if (x == '(') {
			cir++;
			st.push_back(-1);
		}
		else if (x == '[') {
			rec++;
			st.push_back(-2);
		}
		else if (x == ')') {
			if (cir == 0) {
				fail = true;
				break;
			}
			cir--;
			tmp = 0;
			while (true) {
				if (st.back() == -2) {
					fail = true;
					break;
				}
				if (st.back() == -1) {
					st.pop_back();
					if (tmp == 0) {
						tmp = 1;
					}
					st.push_back(tmp * 2);
					break;
				}
				else {
					tmp += st.back();
					st.pop_back();
				}
			}
		}
		else if (x == ']') {
			if (rec == 0) {
				fail = true;
				break;
			}
			rec--;
			tmp = 0;
			while (true) {
				if (st.back() == -1) {
					fail = true;
					break;
				}
				if (st.back() == -2) {
					st.pop_back();
					if (tmp == 0) {
						tmp = 1;
					}
					st.push_back(tmp * 3);
					break;
				}
				else {
					tmp += st.back();
					st.pop_back();
				}
			}
		}
	}
	int ans = 0;
	while (!st.empty())
	{
		ans += st.back();
		st.pop_back();
	}

	if (fail || cir != 0 || rec !=0) {
		ans = 0;
	}
	cout << ans << endl;
}