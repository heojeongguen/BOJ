#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define endl '\n'
typedef long long ll;

set<int> s;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == "add") {
			int d; cin >> d;
			s.insert(d);
		}
		else if (input == "remove") {
			int d; cin >> d;
			s.erase(d);
		}
		else if (input == "check") {
			int d; cin >> d;
			auto iter = s.find(d);
			if (iter == s.end()) cout << 0 << endl;
			else cout << 1 << endl;
		}
		else if (input == "toggle") {
			int d; cin >> d;
			auto iter = s.find(d);
			if (iter == s.end()) s.insert(d);
			else s.erase(d);
		}
		else if (input == "all") {
			for (int i = 1; i <= 20; i++) 
				s.insert(i);
		}
		else {
			s.clear();
		}
	}
}