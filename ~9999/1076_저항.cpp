#include <iostream>
#include <map>
#include <string>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
map<string, pair<int,ll>> m;

int main() {
	m["black"] = { 0,1 };
	m["brown"] = { 1,2 };
	m["red"] = { 2,3 };
	m["orange"] = { 3,4 };
	m["yellow"] = { 4,5 };
	m["green"] = { 5,6 };
	m["blue"] = { 6,7 };
	m["violet"] = { 7,8 };
	m["grey"] = { 8,9 };
	m["white"] = { 9,10 };
	string str, ans;
	cin >> str;
	ans.push_back((m[str].first + '0'));
	cin >> str;
	ans.push_back((m[str].first) + '0');
	cin >> str;
	for (int i = 0; i < m[str].second - 1; i++) {
		ans.push_back('0');
	}
	bool check = false;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] != '0') check = true;
		if (check) cout << ans[i];
	}
	if (!check) cout << 0 << endl;
}