#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'

int L, C;
vector<char> vec;
string str;
void DFS(int now) {
	if (now == C) {
		if (str.size() == L) {
			int jaum = 0, moum = 0;
			for (int i = 0; i < str.size(); i++) {
				if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
					moum++;
				else
					jaum++;
			}
			if(moum >= 1 && jaum >=2)
				cout << str << "\n";
		}
		return;
	}
	str.push_back(vec[now]);
	DFS(now + 1);
	str.pop_back();
	DFS(now + 1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char c; cin >> c;
		vec.push_back(c);
	}
	sort(vec.begin(), vec.end());
	DFS(0);
}