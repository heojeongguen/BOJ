#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<char> vec;
vector<char> L;
vector<char> R;
int cnt[26];
int main() {
	string str;
	string ans;
	char mid = ' ';
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		vec.push_back(str[i]);
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		cnt[vec[i] - 65]++;
	}
	bool find = false;
	int idx_find = 0;
	for (int i = 0; i <= 25; i++) {
		if (cnt[i] % 2 == 1) {
			if (find == false) {
				find = true;
				idx_find = i;
			}
			else {
				cout << "I'm Sorry Hansoo" << endl;
				return 0;
			}
		}
	}

	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == (char)(idx_find + 65) && find == true && cnt[idx_find] % 2 == 1 ) {
			cnt[idx_find]--;
			continue;
		}
		if (i % 2 == 0) {
			L.push_back(vec[i]);
		}
		else {
			R.push_back(vec[i]);
		}
	}
	


	reverse(R.begin(), R.end());
	for (int i = 0; i < L.size(); i++) {
		ans.push_back(L[i]);
	}
	if (find == true) {
		ans.push_back((char)(idx_find + 65));
	}

	for (int i = 0; i < R.size(); i++) {
		ans.push_back(R[i]);
	}
	for (int i = 0; i < ans.size() / 2; i++) {
		if (ans[i] != ans[ans.size() - i - 1]) {
			cout << "I'm Sorry Hansoo" << endl;
			return 0;
		}
	}
	cout << ans << endl;
}