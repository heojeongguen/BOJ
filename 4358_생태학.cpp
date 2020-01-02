#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------
map<string,int> m;
vector<string> vec;
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string input; int cnt = 0;
	while (getline(cin,input)) {
		cnt++;
		auto iter = m.find(input);
		if (iter == m.end()) {
			m.insert({ input,1 });
		}
		else {
			iter->second++;
		}
	}
	for (auto i = m.begin(); i != m.end(); i++) {
		cout.precision(4);
		cout << i->first << " " << fixed << (i->second / (double)cnt) * 100 << endl;
	}
	
}